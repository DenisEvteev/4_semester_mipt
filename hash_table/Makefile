CXX = g++
GCOVFLAGS = -ftest-coverage -fprofile-arcs
CXXFLAGS = -Wall $(GCOVFLAGS) -g
LDLIBS = -lcppunit

SOURCE = Hash_Table.h
TEST_SRC = hashTableTest.h
OBJS = main.o hashTableTest.o Hash_Table.o

HashTable : $(OBJS)
	$(CXX) $^ -o $@ $(LDLIBS) $(LDFLAGS) $(GCOVFLAGS)
	
main.o : $(TEST_SRC)

Hash_Table.o : $(SOURCE)

TEST_SRC += $(SOURCE)

hashTableTest.o : $(TEST_SRC)

clean :
	rm *.o HashTable *.gcno *.gcda *.h.gcov *.cpp.gcov *.gcov
