//
// Created by user on 22/05/2020.
//

#ifndef _PTHREAD_INTEGRATOR_H_
#define _PTHREAD_INTEGRATOR_H_

#include <pthread.h>
#include <sched.h>
#include <cmath>
#include "bound.h"

typedef struct cpu_data
{
	bound_t* bd_;
	unsigned cpu_; // on which logical processor to execute a thread
	cpu_data(bound_t* bd, unsigned cpu)
		: bd_(bd), cpu_(cpu)
	{
		assert(bd_);
	} //just in case

} cpu_data_t;

/*This define is implemented for reporting errors from a pthread functions
 * due to the have special deal in the case of returning error cases
 * So we cannot use errno value */

#define error_abort(ret, message)                                     \
do{                                                                    \
    std::cerr << message << " :\n";                                     \
    std::cerr << __LINE__ << ",  " << __PRETTY_FUNCTION__ << std::endl;  \
    std::cerr << "return value is : " << ret << std::endl;                \
    std::abort();                                                          \
}while(0)

#define func(x) ( 1 / std::log( x ) )

void solve_problem(const bound_t& bound, double& result_per_machine);
void* run(void* arg);
void distribute_relative_cpu(const unsigned cpu);

#define LOOK_AT_THE_CPU_DATA_TYPE


#endif //_PTHREAD_INTEGRATOR_H_
