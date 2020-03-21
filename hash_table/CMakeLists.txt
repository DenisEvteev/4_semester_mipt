cmake_minimum_required(VERSION 3.15)
project(hash_table)

set(CMAKE_CXX_STANDARD 14)

add_executable(hash_table Hash_Table.cpp tests/hashTableTest.cpp tests/hashTableTest.h Hash_Table.h main.cpp)

#tests/hashTableTest.cpp tests/hashTableTest.h Hash_Table.cpp tests/hashTableTest.cpp tests/hashTableTest.h Hash_Table.h main.cpp