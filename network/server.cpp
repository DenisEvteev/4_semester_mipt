//
// Created by user on 15/05/2020.
//

#include "inhead.h"

const double START = 2;
const double FINISH = 70002;

typedef struct task{
	int fd;
	struct sockaddr_in peer;
	bound_t bound;
}task_t;

void init_tcp_connection(int fd);
void produce_broadcast_to_network(int fd);
void distribute_task_per_machine(task_t* tasks, int listen_fd, int workers);

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

	int broadcast = socket(AF_INET, SOCK_DGRAM, 0);
	if(broadcast == -1)
		PANIC(broadcast, "creation datagram socket in server");
	produce_broadcast_to_network(broadcast);

	/*Now we want to set a tcp connection -- it means that a server is going
	 * to give a task for each client in LAN*/

//	int giver = socket(AF_INET, SOCK_STREAM, 0);
//	if(giver == -1)
//		PANIC(giver, "creation of SOCK_STREAM socket");
//
//	init_tcp_connection(giver);
//
//	task_t* tasks = new task_t[n_workers];
//	std::memset(tasks, 0, n_workers * sizeof(task_t));
//
//	distribute_task_per_machine(tasks, giver, n_workers);





	//delete [] tasks;
	return 0;


}

//void distribute_task_per_machine(task_t * tasks, int listen_fd, int workers){
//	assert(tasks && listen_fd >= 0 && workers > 0);
//	int ret;
//	socklen_t addrlen = sizeof(struct sockaddr_in);
//	double save_start = START;
//	double step = (FINISH - START) / static_cast<double>(workers);
//
//	for(int i = 0; i < workers; ++i)
//	{
//		bzero(&tasks[i].peer, sizeof(struct sockaddr));
//		tasks[i].fd = accept(listen_fd, (struct sockaddr*)(&tasks[i].peer), &addrlen);
//		assert(addrlen == sizeof(struct sockaddr_in));
//		if(tasks[i].fd == -1)
//			PANIC(tasks[i].fd, "accepting incomming connection");
//		tasks[i].bound.start  = save_start;
//		tasks[i].bound.finish = ( i == workers - 1 ) ? FINISH : save_start + step;
//		save_start = tasks[i].bound.finish;
//		/*As soon as the connection has been set [ I mean accept has returned the file descriptor for us ]
//		 * we can send data for the remote machine */
//		ret = write(tasks[i].fd, &tasks[i].bound, sizeof(tasks[i].bound));
//		if(ret == -1)
//			PANIC(ret, "write data to peer client socket");
//
//	}
//
//}

//void init_tcp_connection(int fd){
//	assert(fd >= 0);
//	struct sockaddr_in bindaddr;
//	bzero(&bindaddr, sizeof(bindaddr));
//	bindaddr.sin_family      = AF_INET;
//	bindaddr.sin_addr.s_addr = INADDR_ANY;
//	bindaddr.sin_port        = htons(PORT_NUMBER);
//
//	int ret = bind(fd, (struct sockaddr*)&bindaddr, sizeof(bindaddr));
//	if(ret != -1)
//		PANIC(ret, "binding a socket to a well-known adress");
//
//	ret = listen(fd, BACKLOG);
//	if(ret != 0)
//		PANIC(ret, "listening on the giver socket");
//
//}

void produce_broadcast_to_network(int fd){
	assert(fd >= 0);
	const int broadcastEnabled = 1;
	int ret = setsockopt(fd, SOL_SOCKET, SO_BROADCAST, &broadcastEnabled, sizeof(broadcastEnabled));
	if(ret == -1)
		PANIC(ret, "setting SO_BROADCAST option");
	struct sockaddr_in addr;
	bzero(&addr, sizeof(struct sockaddr_in));
	addr.sin_family      = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
	addr.sin_port        = htons(BROADCAST_PORT); // this make os to choose an ephemeral port for communication via a network
	/*At this moment we want to send a BROADCAST datagram via internet domain socket
	 * for make all clients to know the address of server process
	 * which will give a special tasks for them*/
	ret = sendto(fd, NULL, 0, 0, (struct sockaddr*)&addr, sizeof(addr)); // we can send a datagram of zero length
	if(ret == -1)
		PANIC(ret, "sending BROADCAST to the network");

	/*As the input argument for server provide the exact number of clients in the network
	 * which will accept incoming tasks, So I've decided not to wait for the responses from
	 * clients to the broadcast datagram message*/

	/*FIXME : I should think about the case of waiting response from
	 * all the clients via UDP connection for waiting the exact number of them as was provided
	 * via argument in main function I should set a signal -- SIGALARM  to wait for exact period of time
	 * while all the clients respond to the BROADCAST datagram otherwise I should delete the connection
	 * via killing the server process*/

	ret = close(fd);
	if(ret != 0)
		PANIC(ret, "close SOCK_DGRAM socket in server");
}


