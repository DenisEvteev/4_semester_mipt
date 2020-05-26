//
// Created by user on 15/05/2020.
//

#include "inhead.h"

const double START = 2;
const double FINISH = 100002;

void init_tcp_connection(int fd);
void produce_broadcast_to_network(int fd);
void keepalive_settings_for_server(int fd);
/*This function accepts all the connections with peer workers just in a loop*/
void accept_and_get_threads(task_t* tasks, int listen_fd, int workers, int&nfds, int& genthrs);
double perform_parallel_tasks_per_machine(task_t* tasks, int workers, int nfds, int genthrs);


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
	int nfds = giver;
	int genthrs = 0; //this variable will save the general number of threads in all workers
	accept_and_get_threads(tasks, giver, n_workers, nfds, genthrs);
	int ret = close(giver);
	if(ret != 0)
		PANIC(ret, "closing listening socket in server");
	++nfds; // we will use this value as one of arguments to select system call

	double result = perform_parallel_tasks_per_machine(tasks, n_workers, nfds, genthrs);

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

double perform_parallel_tasks_per_machine(task_t* tasks, int workers, int nfds, int genthrs){
	/*Here we know the general number of threads all in all in machines to make the appropriate
	 * distribution of the tasks  ITS value is [ genthrs ] */
	assert(tasks && workers > 0 && genthrs > 0);
	fd_set readfds;   // read result
	fd_set writefds; //write task to machine
	double result = 0;
	double tmp    = 0;
	int    count  = 0; // this variable for detecting condition under which we are going to log off the endless loop
	int ret;      // this variable will collect return values from sys calls

	ssize_t read_b;
	ssize_t write_b;

	double save_start = START;
	double step       = (FINISH - START) / static_cast<double>(genthrs); // amount of task per one thread
	for(;;){
		//initialization of sets
		FD_ZERO(&readfds);
		FD_ZERO(&writefds);
		//filling of sets
		for(int i = 0; i < workers; ++i){
			assert(tasks[i].fd >= 0);
			if(!tasks[i].wrote){
				FD_SET(tasks[i].fd, &writefds);
				++count;
			}
			if(!tasks[i].read_r){ // only for reading result per machine
				FD_SET(tasks[i].fd, &readfds);
				++count;
			}
		}
		//check log off the loop
		if(count == 0)
			break;
		//find ready file descriptors
		ret = select(nfds, &readfds, &writefds, NULL, NULL);
		if(ret == -1)
			PANIC(ret, "select a ready file descriptors");
		//perform I/O [go through each worker]
		for(int i = 0; i < workers; ++i){

			if(!tasks[i].wrote && FD_ISSET(tasks[i].fd, &writefds)){
				//write the exact part of general problem to a worker
				assert(tasks[i].number_thr > 0);
				tasks[i].bound.start = save_start;
				/*How can we consider this point of finish thing*/
				if(FINISH - save_start <= step)
					tasks[i].bound.finish = FINISH;
				else tasks[i].bound.finish = save_start + tasks[i].number_thr * step;
				save_start = tasks[i].bound.finish;

				write_b = write(tasks[i].fd, &tasks[i].bound, sizeof(tasks[i].bound));
				if(write_b != sizeof(tasks[i].bound))
					PANIC(write_b, "error in giving task to a worker");
				tasks[i].wrote = true;
			}
			if(!tasks[i].read_r && tasks[i].wrote && FD_ISSET(tasks[i].fd, &readfds))
			{
				read_b = read(tasks[i].fd, &tmp, sizeof(tmp));
				if(read_b != sizeof(tmp))
					PANIC(read_b, "reading result per machine");
				result += tmp;

				tasks[i].read_r = true;
				ret = close(tasks[i].fd);
				if(ret != 0)
					PANIC(ret, "closing end-point in server (passive closing)");
			}

		}
		count = 0;
	}
	return result;

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

void accept_and_get_threads(task_t* tasks, int listen_fd, int workers, int&nfds, int& genthrs){
	assert(tasks && listen_fd >= 0 && workers > 0);
	int ret;
	socklen_t addrlen = sizeof(struct sockaddr_in);
	int keepaliveEnabled = 1;

	fd_set readfds;
	int count = 0;
	int thr = 0;
	ssize_t read_b;
	for(;;){
		FD_ZERO(&readfds);

		if(thr < workers){
			FD_SET(listen_fd, &readfds);
			++count;
		}
		for(int i = 0; i < workers; ++i)
		{
			if(tasks[i].fd >= 0 && tasks[i].number_thr == 0){
				FD_SET(tasks[i].fd, &readfds);
				++count;
			}
		}
		if(count == 0)
			break;
		ret = select(++nfds, &readfds, NULL, NULL, NULL);
		if(ret == -1)
			PANIC(ret, "select for accepting incomming connections and read number of threads");
		if(FD_ISSET(listen_fd, &readfds)) // accept connection
		{
			tasks[thr].fd = accept4(listen_fd, (struct sockaddr*)(&tasks[thr].peer), &addrlen, SOCK_NONBLOCK);
			if(tasks[thr].fd == -1)
				PANIC(tasks[thr].fd, "accepting incomming connection");
			assert(addrlen == sizeof(struct sockaddr_in));
			ret = setsockopt(tasks[thr].fd, SOL_SOCKET, SO_KEEPALIVE, &keepaliveEnabled, sizeof(keepaliveEnabled));
			if(ret == -1)
				PANIC(ret, "making a server connection KEEPALIVE");
			nfds = std::max(nfds, tasks[thr].fd);
			++thr;
		}
		for(int i = 0; i < workers; ++i){
			//we want to read number of threads in a worker
			if(tasks[i].fd >= 0 && tasks[i].number_thr == 0 && FD_ISSET(tasks[i].fd, &readfds))
			{
				//read number of threads from a worker
				read_b = read(tasks[i].fd, &tasks[i].number_thr, sizeof(tasks[i].number_thr));
				if(read_b != sizeof(tasks[i].number_thr))
					PANIC(read_b, "read number of threads from worker");
				std::cout << "Number threads : " << tasks[i].number_thr << std::endl;
				genthrs += tasks[i].number_thr; // increase the general number of threads in all incarnations of tcp connection
			}

		}
		count = 0;
	}
}


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


