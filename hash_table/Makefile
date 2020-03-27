CXX = g++
GCOV = -fprofile-arcs
GCOVFLAGS = -ftest-coverage $(GCOV)
CXXFLAGS = -Wall $(GCOVFLAGS) -g
LDLIBS = -lcppunit
VALGRIND_FLAGS = --leak-check=full --log-file=val_log

SOURCE = Hash_Table.h
TEST_SRC = tests/hashTableTest.h
OBJS = main.o ./tests/hashTableTest.o Hash_Table.o


HashTable : $(OBJS)
	$(CXX) $^ -o $@ $(LDLIBS) $(GCOV)
	
main.o : $(TEST_SRC)

Hash_Table.o : $(SOURCE)

./tests/hashTableTest.o : $(TEST_SRC) $(SOURCE)

.PHONY: clean
clean :
	rm *.o HashTable *.gcno *.gcda *.h.gcov *.cpp.gcov *.gcov

.PHONY: valgirnd_check
valgrind_check :
	-valgrind $(VALGRIND_FLAGS) ./HashTable
