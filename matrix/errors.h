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
#include <vector>

#define error_abort(str)                                            \
do{                                                                  \
    std::cerr << str << " :\n";                                       \
    std::cerr << __LINE__ << ",  " << __PRETTY_FUNCTION__ << std::endl;\
    std::abort();                                                       \
}while(0)

#endif //ERRORS_H
