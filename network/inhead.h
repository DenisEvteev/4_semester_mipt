//
// Created by user on 15/05/2020.
//

#ifndef _INHEAD_H_
#define _INHEAD_H_



#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

/*I should implement some define for printing actual
 * information about the current error condition that has happened via the call*/

#define PANIC(ret, message)                                \
do{                                                         \
	std::cerr << "Return value is : [ " << ret << " ]\n";    \
	std::cerr << message << std::endl;                        \
	std::cerr << "errno == " << errno << std::endl;            \
	std::cerr << "Error line is : [ " << __LINE__  << " ]\n";   \
}while(0)                                                        \

#define PORT_NUMBER    50002
#define BROADCAST_PORT 9009
/*this value will be used for creating a string to see the server address in
 * client for debug purpose*/
#define MAX_LENGTH_IPV4_ADDRESS INET_ADDRSTRLEN

#define BACKLOG SOMAXCONN

typedef struct bound{
	double start;
	double finish;
}bound_t;


#define func(x) ( 1 / std::log( x ) )

#endif //_INHEAD_H_
