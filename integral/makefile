CXX = g++
PTHREAD_FLAG = -pthread
CXXFLAGS = -Wall -std=c++11 $(PTHREAD_FLAG)

HEADERS = error.h
OBJS = main.o

.PHONY : all
all : main

#linking all the object files
main : $(OBJS)
	$(CXX) -o $@ $^ $(PTHREAD_FLAG)

main.o : $(HEADERS)


.PHONY : clean
clean :
	rm *.o main