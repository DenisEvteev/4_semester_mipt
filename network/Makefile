#This makefile construct two executable files \
one for server process and another for worker one

CXX          = g++
PTHREAD_FLAG = -pthread
FLAGS        = -Wall -std=c++11 -O3
CXXFLAGS    := $(FLAGS) $(PTHREAD_FLAG)

HEADERS          = inhead.h bound.h
SRC_SERVER       = server.cpp
SRC_WORKER       = worker.cpp
WORKER_HEADERS  := $(HEADERS) pthread_integrator.h

OBJS             = pthread_integrator.o worker.o


.PHONY : all
all : worker server

server : $(HEADERS) $(SRC_SERVER)
	$(CXX) $(FLAGS) -o $@ $^

worker : $(OBJS)
	$(CXX) -o $@ $^ $(PTHREAD_FLAG)

pthread_integrator.o : bound.h
worker.o             : $(WORKER_HEADERS)


.PHONY : clean
clean :
	-rm worker server *.o