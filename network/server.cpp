//
// Created by user on 15/05/2020.
//

#include "inhead.h"

const double START = 2;
const double FINISH = 70002;

void init_tcp_connection(int fd);
void produce_broadcast_to_network(int fd);
void keepalive_settings_for_server(int fd);
/*This function accepts all the connections with peer workers just in a loop*/
double perform_parallel_tasks_per_machine(task_t* tasks, int listen_fd, int workers);


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

double perform_parallel_tasks_per_machine(task_t* tasks, int listen_fd, int workers){
	assert(tasks && listen_fd >= 0 && workers > 0);
	int ret;
	int genthrs = 0; //this variable will save the general number of threads in all workers
	socklen_t addrlen = sizeof(struct sockaddr_in);
	int keepaliveEnabled = 1;

	int read_threads_number = 0;
	fd_set readfds, writefds;
	double result = 0, tmp = 0;
	int count = 0, thr = 0;
	ssize_t read_b, write_b;

	double save_start = START;
#define STEP (FINISH - START) / static_cast<double>(genthrs)
#define FD(i) tasks[i].fd
#define NUM_THR tasks[i].number_thr

	int max = listen_fd;
	for(;;){
		FD_ZERO(&readfds);
		FD_ZERO(&writefds);

		if(thr < workers){
			FD_SET(listen_fd, &readfds);
			++count;
		}
		for(int i = 0; i < workers; ++i)
		{
			/* this filling both for : reading a thread number and result per machine*/
			if(FD(i) >= 0 && !tasks[i].read_r){
				FD_SET(FD(i), &readfds);
				++count;
			}
			if(read_threads_number == workers && !tasks[i].wrote){
				assert(FD(i) >= 0 && NUM_THR > 0);
				FD_SET(FD(i), &writefds);
				++count;
			}

		}
		if(count == 0)
			break;
		++max;
		ret = select(( max > FD_SETSIZE ? FD_SETSIZE : max ),  &readfds, &writefds, NULL, NULL);
		if(ret == -1)
			PANIC(ret, "select for accepting incomming connections and read number of threads");


		if(FD_ISSET(listen_fd, &readfds)) // accept connection
		{
			FD(thr) = accept4(listen_fd, (struct sockaddr*)(&tasks[thr].peer), &addrlen, SOCK_NONBLOCK);
			if(FD(thr) == -1)
				PANIC(FD(thr), "accepting incomming connection");
			assert(addrlen == sizeof(struct sockaddr_in));
			ret = setsockopt(FD(thr), SOL_SOCKET, SO_KEEPALIVE, &keepaliveEnabled, sizeof(keepaliveEnabled));
			if(ret == -1)
				PANIC(ret, "making a server connection KEEPALIVE");
			++thr;
			max = std::max(max, FD(thr));
		}
#define SEG tasks[i].bound
		for(int i = 0; i < workers; ++i){
			//we want to read number of threads in a worker
			if(FD(i) >= 0 && NUM_THR == 0 && FD_ISSET(FD(i), &readfds))
			{
				//read number of threads from a worker
				read_b = read(FD(i), &NUM_THR, sizeof(NUM_THR));
				if(read_b != sizeof(NUM_THR))
					PANIC(read_b, "read number of threads from worker");
				std::cout << "Number threads : " << NUM_THR << std::endl;
				genthrs += NUM_THR; // increase the general number of threads in all incarnations of tcp connection
				/*Now we should increment a value which corresponds for condition under which
				 * we can write bounds for a peer server*/
				read_threads_number++;
			}
			/*Now I should think about the conditions under which I can consider the file descriptors
			 * ready in terms for writing a special task bounds for calculating */
			if(FD(i) >= 0 && FD_ISSET(FD(i), &writefds)){
				assert(NUM_THR > 0);
				SEG.start = save_start;
				/*How can we consider this point of finish thing*/
				if(FINISH - save_start <= STEP)
					SEG.finish = FINISH;
				else SEG.finish = save_start + NUM_THR * STEP;
				save_start = SEG.finish;

				write_b = write(FD(i), &SEG, sizeof(SEG));
				if(write_b != sizeof(SEG))
					PANIC(write_b, "error in giving task to a worker");
				tasks[i].wrote = true;
			}

			if(tasks[i].wrote && FD_ISSET(FD(i), &readfds)){
				read_b = read(FD(i), &tmp, sizeof(tmp));
				if(read_b != sizeof(tmp))
					PANIC(read_b, "reading result per machine");

				result += tmp;
				tasks[i].read_r = true;
				ret = close(FD(i));
				if(ret != 0)
					PANIC(ret, "closing end-point in server (passive closing)");
			}


		}
		count = 0;
	}

	return result;
}

#undef STEP
#undef FD
#undef SEG
#undef NUM_THR

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


