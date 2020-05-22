//
// Created by user on 20/05/2020.
//

#include "inhead.h"

const double move = 0.0001;
#define SHOW_SERVER_ADDRESS
void retrieve_task_from_server(bound_t& bound, int fd, const struct in_addr& addr);
void retrieve_server_address(struct sockaddr_in& addr, int fd);

int main(int argc, char ** argv)
{
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
	retrieve_task_from_server(bound, taker, server.sin_addr);
	/*As soon a client takes a task it should calculate it in parallel using
	 * the maximum threads as it could for progressive work*/

	/*I'm going to calculate the task using maximum number of available threads  on the machine
	 * This value is equal to the number of available virtua cpus in the machine*/
	int threads = static_cast<int>(sysconf(_SC_NPROCESSORS_ONLN));
	double save_start = bound.start;
	unsigned current_number_proc = 0;
	double step = (bound.finish - bound.start) / static_cast<double>(threads);
	/*At this moment we understand that we want to execute the task on the number of threads
	 * which is equal to the number of available processors in the system
	 * So, Each thread will be distributed to its */


	return 0;






}

void retrieve_server_address(struct sockaddr_in& addr, int fd)
{
	assert( fd >= 0 );
	struct sockaddr_in addrbind;
	bzero(&addrbind, sizeof(addrbind));
	addrbind.sin_family      = AF_INET;
	addrbind.sin_port        = htons(BROADCAST_PORT);
	addrbind.sin_addr.s_addr = INADDR_ANY;
	socklen_t addrlen = sizeof(addrbind);
	int ret = bind(fd, (struct sockaddr *)&addrbind, addrlen);
	if(ret == -1)
		PANIC(ret, "binding client socket to well known address to receive a host's address");
	/* receive a server address and preserve it for further
	 * manipulation with network packets*/
	ret = recvfrom(fd, NULL, 0, 0, (struct sockaddr*)&addr, &addrlen);
	if(ret == -1)
		PANIC(ret, "retrieving a remote server address");
	std::cerr << "I am client. I have received an adress of a server" << std::endl;
#ifdef SHOW_SERVER_ADDRESS
	char paddr[MAX_LENGTH_IPV4_ADDRESS];
	std::memset(paddr, 0, MAX_LENGTH_IPV4_ADDRESS);
	if(inet_ntop(AF_INET, &addr.sin_addr, paddr, MAX_LENGTH_IPV4_ADDRESS))
		std::cout << paddr << std::endl;
	else PANIC(-1, "error in converting network byte ordered server address to presentation");
#endif

}
//void retrieve_task_from_server(bound_t& bound, int fd, const struct in_addr& addr)
//{
//	assert(fd >= 0);
//	struct sockaddr_in addr_tcp;
//	bzero(&addr_tcp, sizeof(addr_tcp));
//	addr_tcp.sin_family  = AF_INET;
//	addr_tcp.sin_port    = htons(PORT_NUMBER);
//	addr_tcp.sin_addr    = addr;
//	socklen_t addrlen = sizeof(addr_tcp);
//	int ret = connect(fd, (struct sockaddr*)(&addr_tcp), addrlen);
//	assert(addrlen == sizeof(addr_tcp));
//	if(ret == -1)
//		PANIC(ret, "making a connection to a peer server");
//
//	ssize_t read_bytes = read(fd, &bound, sizeof(bound));
//	if(read_bytes != sizeof(bound))
//		PANIC(read_bytes, "read bounds from a server for making a solution for the task");
//
//	/*After a client calculate a value corresponding to it he will write the result back
//	 * to the socket to make server know about the actual result*/
//
//}

