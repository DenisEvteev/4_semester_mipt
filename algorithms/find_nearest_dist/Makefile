CXX = g++
CXXFLAGS = -Wall -std=c++17
#[NOTICE : IF YOU WANT TO RUN MY TESTS]\
if You want to run tests which are situated in tests directory You should define \
LDLIBS flag with [-lcppunit] value then this makefile will make the executable for running prepared tests


LDLIBS = -lcppunit


OBJS = main.o Solution.o
HEADERS_FOR_SOLUTION = Solution.h merge.hpp
HEADERS = $(HEADERS_FOR_SOLUTION)


ifeq ($(LDLIBS), -lcppunit)
OBJS += tests/testSolution.o
HEADERS += tests/testSolution.h
endif


.PHONY: all

all : find_nearest_dist

find_nearest_dist : $(OBJS)
	$(CXX) -o $@ $^ $(LDLIBS)

ifeq ($(LDLIBS), -lcppunit)
.PHONY : subsystem
subsystem :
	cd tests/ && $(MAKE)
endif

main.o : $(HEADERS)

Solution.o : $(HEADERS_FOR_SOLUTION)

.PHONY: clean
clean :
	-rm find_nearest_dist $(OBJS)
	cd tests/ && $(CMAKE) clean