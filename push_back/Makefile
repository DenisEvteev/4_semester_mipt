CXX = g++
#[-ftest-coverage] flag is used while compiling
#to produce *.gcno file which is situated at the same directory as the object file
#
GCOV = -fprofile-arcs
CXXFLAGS = -Wall -g -ftest-coverage $(GCOV)
VAL_FLAGS = --leak-check=full --log-file=./tests/val_log
LDLIBS = -lcppunit

SRC = ./tests/testVector.h

GOAL = main
OBJS = tests/testVector.o main.o


.PHONY: all
all : $(GOAL)

.PHONY: subsystem
subsystem :
	cd tests/ && $(MAKE)

main : $(OBJS)
	$(CXX) $^ -o $@ $(LDLIBS) $(GCOV)

main.o : $(SRC)

.PHONY: clean
clean :
	-cd tests/ && $(MAKE) clean
	-rm $(GOAL) *.o val_log run *.gcda *.gcno *.h.gcov *.cpp.gcov *.gcov

.PHONY: run
run : $(GOAL)
	valgrind $(VAL_FLAGS) ./main >./tests/$@