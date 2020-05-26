//
// Created by user on 20/05/2020.
//


#include "inhead.h"
#include "pthread_integrator.h"

void retrieve_task_from_server(bound_t& bound, int fd, const struct in_addr& addr, int threads);
void retrieve_server_address(struct sockaddr_in& addr, int fd);

int main(int argc, char ** argv)
{
	if(argc != 2){
		std::cout << "Bad amount of arguments for worker" << std::endl;
		exit(EXIT_FAILURE);
	}
	int threads = std::atoi(argv[1]); // worker will take an argument of number of threads to run a program with
	assert(threads > 0);

	struct sockaddr_in server; //this variable will contain the address of peer socket host
	bzero(&server, sizeof(server));

	int broadcast = socket(AF_INET, SOCK_DGRAM, 0);
	if(broadcast == -1)
		PANIC(broadcast, "creation SOCK_DGRAM in client");
	retrieve_server_address(server, broadcast);

	int ret = close(broadcast);
	if(ret != 0)
		PANIC(ret, "closing SOCK_DGRAM socket in client");
	/*At this moment a client has already received an address of peer server, so It can
	* connect to it and get his own task to work on*/
	int taker = socket(AF_INET, SOCK_STREAM, 0);
	if(taker == -1)
		PANIC(taker, "creation SOCK_STREAM in client");
	bound_t bound;
	bzero(&bound, sizeof(bound));
	retrieve_task_from_server(bound, taker, server.sin_addr, threads);

	double res_per_machine = 0;
	solve_problem(bound, res_per_machine, threads);

	/*After  calculating the result per machine we should send it to the peer server
	 * who gave us this task and after it we should close the connection*/
	ssize_t b_wr = write(taker, &res_per_machine, sizeof(res_per_machine));
	if(b_wr != sizeof(res_per_machine))
		PANIC(b_wr, "writing result per machine into the socket to server");

	ret = close(taker);
	if(ret != 0)
		PANIC(ret, "closing SOCK_STREAM in worker");

	return 0;
}


void retrieve_server_address(struct sockaddr_in& addr, int fd)
{
	assert( fd >= 0 );
	struct sockaddr_in addrbind = {
		.sin_family      = AF_INET,
		.sin_port        = htons(BROADCAST_PORT),
		.sin_addr        = { .s_addr = INADDR_ANY}
	};

	int getBroadcast = 1;
	int ret = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &getBroadcast, sizeof(getBroadcast));
	if(ret == -1)
		PANIC(ret, "setting SO_REUSEADDR in worker");
	socklen_t addrlen = sizeof(addrbind);
	ret = bind(fd, (struct sockaddr *)&addrbind, addrlen); // this part is pivotal -- otherwise a worker won't be able to get a broadcast packet
	if(ret == -1)
		PANIC(ret, "binding client socket to well known address to receive a host's address");
	/* receive a server address and preserve it for further
	 * manipulation with network packets*/
	ret = recvfrom(fd, NULL, 0, 0, (struct sockaddr*)&addr, &addrlen);
	if(ret == -1)
		PANIC(ret, "retrieving a remote server address");
#ifdef SHOW_SERVER_ADDRESS
	char paddr[MAX_LENGTH_IPV4_ADDRESS];
	std::memset(paddr, 0, MAX_LENGTH_IPV4_ADDRESS);
	if(inet_ntop(AF_INET, &addr.sin_addr, paddr, MAX_LENGTH_IPV4_ADDRESS))
		std::cout << paddr << std::endl;
	else PANIC(-1, "error in converting network byte ordered server address to presentation");
#endif

}

void retrieve_task_from_server(bound_t& bound, int fd, const struct in_addr& addr, int threads)
{
	assert(fd >= 0 && threads >= 1);
	struct sockaddr_in addr_tcp {
		.sin_family  = AF_INET,
		.sin_port    = htons(PORT_NUMBER),
		.sin_addr    = addr
	};

	socklen_t addrlen = sizeof(addr_tcp);
	/*This call felt down due to I haven't create a listening socket to this port so
	 * the return value was errno == ECONNREFUSED */
	int ret = connect(fd, (struct sockaddr*)(&addr_tcp), addrlen);
	if(ret == -1)
		PANIC(ret, "making a connection to a peer server");

	ssize_t write_bytes = write(fd, &threads, sizeof(threads));
	if(write_bytes != sizeof(threads))
		PANIC(write_bytes, "writing number of threads for server from worker");

	ssize_t read_bytes = read(fd, &bound, sizeof(bound));
	if(read_bytes != sizeof(bound))
		PANIC(read_bytes, "read bounds from a server for making a solution for the task");

	std::cout << "bounds are : [ " << bound.start << " ; " << bound.finish << " ]" << std::endl;

}


