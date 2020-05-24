//
// Created by user on 15/05/2020.
//

#ifndef _INHEAD_H_
#define _INHEAD_H_


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <cstring>
#include <arpa/inet.h>
#include <sys/types.h>
#include <algorithm>
#include <sys/socket.h>


#include "bound.h"

/*I should implement some define for printing actual
 * information about the current error condition that has happened via the call*/

#define PANIC(ret, message)                                \
do{                                                         \
	std::cerr << "Return value is : [ " << ret << " ]\n";    \
	std::cerr << message << std::endl;                        \
	std::cerr << "errno == " << errno << std::endl;            \
	std::cerr << "Error line is : [ " << __LINE__  << " ]\n";   \
	std::abort();                                                \
}while(0)                                                         \

#define PORT_NUMBER    50002
#define BROADCAST_PORT 9009
#define SALT -1
/*this value will be used for creating a string to see the server address in
 * client for debug purpose*/
#define MAX_LENGTH_IPV4_ADDRESS INET_ADDRSTRLEN

#define BACKLOG SOMAXCONN


typedef struct task{
	int fd;
	struct sockaddr_in peer;
	bound_t bound;
}task_t;


#endif //_INHEAD_H_
