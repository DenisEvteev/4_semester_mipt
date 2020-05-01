//
// Created by user on 31/03/2020.
//

#ifndef ERRORS_H
#define ERRORS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
#include <sys/syscall.h>
#include <stdexcept>
#include <sys/resource.h>
#include <cstring>
#include <sys/user.h>
#include <cmath>


typedef struct bound
{
	double start;
	double finish;
	bound(double st, double f)
		: start(st), finish(f)
	{}
} bound_t;

typedef struct cpu_data
{
	bound_t *bd_;
	unsigned cpu_; // on which logical processor to execute a thread
	cpu_data(bound_t *bd, unsigned cpu)
		: bd_(bd), cpu_(cpu)
	{ assert(bd_); } //just in case

} cpu_data_t;

#define error_abort(str, ret)                                            \
do{                                                                  \
    std::cerr << str << " :\n";                                       \
    std::cerr << __LINE__ << ",  " << __PRETTY_FUNCTION__ << std::endl;\
    std::cerr << "return value is : " << ret << std::endl;              \
    std::abort();                                                       \
}while(0)

#endif //ERRORS_H
