//
// Created by user on 15/05/2020.
//

#include "inhead.h"

const double START = 2;
const double FINISH = 100002;

void init_tcp_connection(int fd);
void produce_broadcast_to_network(int fd);
void distribute_task_per_machine(task_t* tasks, int listen_fd, int workers, int& nfds);
double read_result_per_machine(int nfds, task_t* tasks, int workers);
void keepalive_settings_for_server(int fd);

/*In my realization server will take an additional argument -- the number of clients in
 * the architecture. This way will simplify dealing with connections through a LAN
 * So, I'm going to take a lot of advantages from this fact!!!*/
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
	std::memset(tasks, 0, n_workers * sizeof(task_t));

	int nfds = 0;
	distribute_task_per_machine(tasks, giver, n_workers, nfds);
	++nfds; // we will use this value as one of arguments to select system call

	double result = read_result_per_machine(nfds, tasks, n_workers);
	std::cout << result << std::endl;

	delete [] tasks;
	return 0;


}

void keepalive_settings_for_server(int fd)
{
	assert(fd >= 0);
	int seconds = 3;
	int ret = setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &seconds, sizeof(seconds));
	if(ret == -1)
		PANIC(ret, "setting TCP_KEEPALIVE option on the server socket");
	int intvl = 2;
	ret = setsockopt(fd, IPPROTO_TCP, TCP_KEEPINTVL, &intvl, sizeof(intvl));
	if(ret == -1)
		PANIC(ret, "setting TCP_KEEPINTVL option on the server socket");
	int probes = 3;
	ret = setsockopt(fd, IPPROTO_TCP, TCP_KEEPCNT, &probes, sizeof(probes));
	if(ret == -1)
		PANIC(ret, "setting TCP_KEEPCNT option on the server socket");


}

double read_result_per_machine(int nfds, task_t* tasks, int workers){
	assert(nfds > 0 && tasks && workers > 0);
	fd_set readfds;
	int counts = 0;
	int ready = 0;
	double result = 0;
	for(;;){
		FD_ZERO(&readfds);
		for(int i = 0; i < workers; ++i){
			if(tasks[i].fd >= 0){
				FD_SET(tasks[i].fd, &readfds);
				++counts;
			}
		}
		if(counts == 0)
			break;
		ready = select(nfds, &readfds, NULL, NULL, NULL);
		if(ready == -1)
			PANIC(ready, "select a ready file descriptor to read a res_per_machine");
		/*In this loop I check each file descriptors on own in the set*/
		double tmp = 0;
		int ret;
		/*I have one interesting situation when a peer application was killed with a signal
		 * For checking the case of available read operation from a worker it returns just zero due to we can read
		 * now a data from peer socket*/
		for(int i = 0; i < workers; ++i){
			if(FD_ISSET(tasks[i].fd, &readfds)){
				ret = read(tasks[i].fd, &tmp, sizeof(tmp));
				if(ret == 0){
					std::cout << "A worker has died, the process to finish" << std::endl;
					exit(EXIT_FAILURE);
				}
				if(ret == -1)
					PANIC(ret, "reading result per machine");

				result += tmp;
				ret = close(tasks[i].fd);
				if(ret == -1)
					PANIC(ret, "closing file descriptor of communication with peer socket");
				tasks[i].fd = SALT;
			}
		}

		counts = 0;
	}
	return result;
}

void distribute_task_per_machine(task_t * tasks, int listen_fd, int workers, int& nfds){
	assert(tasks && listen_fd >= 0 && workers > 0);
	int ret;
	socklen_t addrlen = sizeof(struct sockaddr_in);
	double save_start = START;
	double step = (FINISH - START) / static_cast<double>(workers);
	int keepaliveEnabled = 1;
	for(int i = 0; i < workers; ++i)
	{
		bzero(&tasks[i].peer, sizeof(struct sockaddr));
		tasks[i].fd = accept4(listen_fd, (struct sockaddr*)(&tasks[i].peer), &addrlen, SOCK_NONBLOCK);
		if(tasks[i].fd == -1)
			PANIC(tasks[i].fd, "accepting incomming connection");
		assert(addrlen == sizeof(struct sockaddr_in));
		ret = setsockopt(tasks[i].fd, SOL_SOCKET, SO_KEEPALIVE, &keepaliveEnabled, sizeof(keepaliveEnabled));
		if(ret == -1)
			PANIC(ret, "making a server connection KEEPALIVE");
		nfds = std::max(nfds, tasks[i].fd);
		tasks[i].bound.start  = save_start;
		tasks[i].bound.finish = ( i == workers - 1 ) ? FINISH : save_start + step;
		save_start = tasks[i].bound.finish;
		/*As soon as the connection has been set [ I mean accept has returned the file descriptor for us ]
		 * we can send data for the remote machine */
		ret = write(tasks[i].fd, &tasks[i].bound, sizeof(tasks[i].bound));
		if(ret == -1)
			PANIC(ret, "write data to peer client socket");

	}

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


