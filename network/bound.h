//
// Created by user on 22/05/2020.
//

#ifndef _BOUND_H_
#define _BOUND_H_

#include <iostream>
#include <unistd.h>
#include <cassert>

typedef struct bound{
	double start  = 0;
	double finish = 0;
	bound(double st, double f)
		: start(st), finish(f)
	{
	}
	bound() = default;
}bound_t;

#endif //_BOUND_H_
