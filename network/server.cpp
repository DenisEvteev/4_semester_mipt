//
// Created by user on 15/05/2020.
//

/*I have made it !!! It's a very happy moment in the life. I promised my brother that
 * I will succed in it --- and I've made. It was a very difficult year of programming
 * So, thanks Denis Lunev for this I will never forger about such adventures
 *
 * NOW I'm going to make a commit with a message about a VICTORY!!! */


#include "inhead.h"

const double START = 2;
const double FINISH = 70002;

void init_tcp_connection(int fd);
void produce_broadcast_to_network(int fd);
void keepalive_settings_for_server(int fd);
double perform_parallel_tasks_per_machine(task_t* tasks, int listen_fd, int workers);
void accept_worker(int listen_fd, int& fd, int& max);
void read_number_of_threads(int fd, int& numthr);
void write_task_to_worker(task_t* tasks, int id_, double& save_start, const int genthrs);
double read_result_from_worker(int fd);
int init_sets_for_monitoring(task_t* tasks, fd_set& readfds, fd_set& writefds, int workers, int listen_fd,
	int thr, int read_threads_number);

int main(int argc, char ** argv)
{
	if(argc != 2)
	{
		std::cerr << "Bad amount of input arguments\n";
		std::exit(EXIT_FAILURE);
	}
	int n_workers = std::atoi(argv[1]);
	assert(n_workers > 0);

	int giver = socket(AF_INET, SOCK_STREAM, 0);
	if(giver == -1)
		PANIC(giver, "creation of SOCK_STREAM socket");

	init_tcp_connection(giver);
	keepalive_settings_for_server(giver);

	int broadcast = socket(AF_INET, SOCK_DGRAM, 0);
	if(broadcast == -1)
		PANIC(broadcast, "creation datagram socket in server");
	produce_broadcast_to_network(broadcast);

	task_t* tasks = new task_t[n_workers];
	double result = perform_parallel_tasks_per_machine(tasks, giver, n_workers);
	int ret = close(giver);
	if(ret != 0)
		PANIC(ret, "closing listening socket in server");

	std::cout << result << std::endl;

	delete [] tasks;
	return 0;


}

void keepalive_settings_for_server(int fd)
{
	assert(fd >= 0);
	int seconds = 5;
	int ret = setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &seconds, sizeof(seconds));
	if(ret == -1)
		PANIC(ret, "setting TCP_KEEPALIVE option on the server socket");
	int intvl = 3;
	ret = setsockopt(fd, IPPROTO_TCP, TCP_KEEPINTVL, &intvl, sizeof(intvl));
	if(ret == -1)
		PANIC(ret, "setting TCP_KEEPINTVL option on the server socket");
	int probes = 2;
	ret = setsockopt(fd, IPPROTO_TCP, TCP_KEEPCNT, &probes, sizeof(probes));
	if(ret == -1)
		PANIC(ret, "setting TCP_KEEPCNT option on the server socket");

}

void init_tcp_connection(int fd){
	assert(fd >= 0);
	struct sockaddr_in bindaddr {
		.sin_family   = AF_INET,
		.sin_port     = htons(PORT_NUMBER),
		.sin_addr     = { .s_addr = INADDR_ANY}
	};

	int reuseaddrEnabled = 1;
	int ret = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuseaddrEnabled, sizeof(reuseaddrEnabled));
	if(ret == -1)
		PANIC(ret, "enabling SO_REUSEADDR option to the server process");
 	ret = bind(fd, (struct sockaddr*)&bindaddr, sizeof(bindaddr));
	if(ret == -1)
		PANIC(ret, "binding a socket to a well-known adress");

	ret = listen(fd, BACKLOG);
	if(ret != 0)
		PANIC(ret, "listening on the giver socket");

}

#define STEP(gen_num_threads) (FINISH - START) / static_cast<double>(gen_num_threads)
#define FD(i)                 tasks[i].fd
#define NUM_THR(i)            tasks[i].number_thr
#define SEG(i)                tasks[i].bound
#define WR(i)                 tasks[i].wrote
#define RD(i)                 tasks[i].read_r

double perform_parallel_tasks_per_machine(task_t* tasks, int listen_fd, int workers){
	assert(tasks && listen_fd >= 0 && workers > 0);
	int ret;
	int genthrs = 0; //this variable will save the general number of threads in all workers

	int read_threads_number = 0;
	fd_set readfds, writefds;

	double result = 0;
	int thr = 0;

	double save_start = START;

	int max = listen_fd;
	for(;;){

		if(init_sets_for_monitoring(tasks, readfds, writefds,
			workers, listen_fd, thr, read_threads_number) == 0)
			break;
		++max;
		ret = select(( max > FD_SETSIZE ? FD_SETSIZE : max ),  &readfds, &writefds, NULL, NULL);
		if(ret == -1)
			PANIC(ret, "select for accepting incomming connections and read number of threads");


		if(FD_ISSET(listen_fd, &readfds)) // accept connection
		{
			accept_worker(listen_fd, FD(thr), max);
			++thr;
		}
		for(int i = 0; i < workers; ++i){

			if(FD(i) >= 0 && NUM_THR(i) == 0 && FD_ISSET(FD(i), &readfds))
			{
				read_number_of_threads(FD(i), NUM_THR(i));
				read_threads_number++;
				assert(NUM_THR(i) > 0);
				genthrs += NUM_THR(i);
			}

			if(FD(i) >= 0 && FD_ISSET(FD(i), &writefds)){
				write_task_to_worker(tasks, i, save_start, genthrs);
				WR(i) = true;
			}

			if(WR(i) && FD_ISSET(FD(i), &readfds)){
				result += read_result_from_worker(FD(i));
				RD(i) = true;
			}


		}
	}

	return result;
}

void accept_worker(int listen_fd, int& fd, int& max)
{
	/*at the case of accepting new incomming connection
	 * file descriptor should be filled with negative value*/
	assert(fd == -1);
	int keepaliveEnabled = 1;
	int ret;
	fd = accept4(listen_fd, NULL, 0, SOCK_NONBLOCK);
	if(fd == -1)
		PANIC(fd, "accepting incomming connection");
	ret = setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, &keepaliveEnabled, sizeof(keepaliveEnabled));
	if(ret == -1)
		PANIC(ret, "making a server connection KEEPALIVE");
	max = std::max(max, fd);
}

void read_number_of_threads(int fd, int& numthr){
	ssize_t read_b = 0;
	read_b = read(fd, &numthr, sizeof(numthr));
	if(read_b != sizeof(numthr))
		PANIC(read_b, "read number of threads from worker");
	std::cout << "Number threads in fd : [ " << fd << " ] === " << numthr << std::endl;
}

void write_task_to_worker(task_t* tasks, int id_, double& save_start, const int genthrs)
{
	assert(tasks);
	assert(NUM_THR(id_) > 0);
	ssize_t write_b;
	SEG(id_).start = save_start;

	if(FINISH - save_start <= STEP(genthrs))
		SEG(id_).finish = FINISH;
	else SEG(id_).finish = save_start + NUM_THR(id_) * STEP(genthrs);
	save_start = SEG(id_).finish;

	write_b = write(FD(id_), &SEG(id_), sizeof(SEG(id_)));
	if(write_b != sizeof(SEG(id_)))
		PANIC(write_b, "error in giving task to a worker");
}

double read_result_from_worker(int fd)
{
	assert(fd >= 0);
	double tmp = 0;
	ssize_t read_b = read(fd, &tmp, sizeof(tmp));
	if(read_b != sizeof(tmp))
		PANIC(read_b, "reading result per machine");

	int ret = close(fd);
	if(ret != 0)
		PANIC(ret, "closing end-point in server (passive closing)");

	return tmp;
}

int init_sets_for_monitoring(task_t* tasks, fd_set& readfds, fd_set& writefds, int workers, int listen_fd,
	int thr, int read_threads_number)
{
	FD_ZERO(&readfds);
	FD_ZERO(&writefds);

	int count = 0;
	if(thr < workers){
		FD_SET(listen_fd, &readfds);
		++count;
	}
	for(int i = 0; i < workers; ++i)
	{
		/* this filling both for : reading a thread number and result per machine*/
		if(FD(i) >= 0 && !RD(i)){
			FD_SET(FD(i), &readfds);
			++count;
		}
		if(read_threads_number == workers && !WR(i)){
			assert(FD(i) >= 0 && NUM_THR(i) > 0);
			FD_SET(FD(i), &writefds);
			++count;
		}

	}
	return count;
}

#undef STEP
#undef FD
#undef SEG
#undef NUM_THR
#undef WR
#undef RD

void produce_broadcast_to_network(int fd){
	assert(fd >= 0);
	const int broadcastEnabled = 1;
	int ret = setsockopt(fd, SOL_SOCKET, SO_BROADCAST, &broadcastEnabled, sizeof(broadcastEnabled));
	if(ret == -1)
		PANIC(ret, "setting SO_BROADCAST option");
	struct sockaddr_in addr {
		.sin_family      = AF_INET,
		.sin_port        = htons(BROADCAST_PORT),
		.sin_addr        = { .s_addr = htonl(INADDR_BROADCAST) }
	};


	ret = sendto(fd, NULL, 0, 0, (struct sockaddr*)&addr, sizeof(addr)); // we can send a datagram of zero length
	if(ret == -1)
		PANIC(ret, "sending BROADCAST to the network");


	ret = close(fd);
	if(ret != 0)
		PANIC(ret, "close SOCK_DGRAM socket in server");
}


