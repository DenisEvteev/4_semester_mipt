//
// Created by user on 15/03/2020.
//

#ifndef HASHTABLETEST_H
#define HASHTABLETEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/Test.h>
#include <cppunit/TestCaller.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

#include "../Hash_Table.h"
#include <map>


#define _FILL_HASH_TABLE_RANDOM_NUMBERS_IN_RANGE(ht, n)       \
do{                                                            \
    for(int i = 0; i < n; ++i){                                 \
        ht.insert(std::rand());                                       \
    }                                                             \
}while(0)


#define DUMP_IN_FILE(str, stream, ht)                                  \
do{                                                                     \
    std::ofstream stream(str);                                           \
    if(!stream.good()){                                                   \
        std::cerr << "Error in setting output stream!!!" << std::endl;     \
        return;                                                             \
    }                                                                        \
    stream << ht;                                                             \
    stream.close();                                                            \
}while(0)                                                                       \

enum
{
	EDA_ = 3802,
	_BIG_NUMBER = 512
};

class hashTableTest: public CppUnit::TestFixture
{

	/*I should write some tests for checking copy algorithm via std::stack container*/
	using map = std::multimap<std::size_t, int>;

	static void testConstructorThrow();
	static void testZeroSize();
	static void testInsertElement();
	static void testInsertBigAmountAndErase();
	static void testIncrementDecrementOperators();
	static void testOperatorDumpingIntoFile();
	static void testCopyConstructorAssignmentOperator();
	static void testEasyCoverage();
	static void testMoveConstructor();
	static void testMoveAssignmentOperator();
	static void testExceptionCaseAssignmentOperator();
	static void testExceptionCaseCopyConstructor();
private :
CPPUNIT_TEST_SUITE(hashTableTest);
		CPPUNIT_TEST_EXCEPTION(testZeroSize, std::invalid_argument);
		CPPUNIT_TEST(testInsertElement);
		CPPUNIT_TEST(testInsertBigAmountAndErase);
		CPPUNIT_TEST(testCopyConstructorAssignmentOperator);
		CPPUNIT_TEST(testIncrementDecrementOperators);
		CPPUNIT_TEST(testOperatorDumpingIntoFile);
		CPPUNIT_TEST(testEasyCoverage);
		CPPUNIT_TEST_EXCEPTION(testConstructorThrow, std::bad_alloc);
		CPPUNIT_TEST(testMoveConstructor);
		CPPUNIT_TEST(testMoveAssignmentOperator);
		CPPUNIT_TEST(testExceptionCaseAssignmentOperator);
		CPPUNIT_TEST_EXCEPTION(testExceptionCaseCopyConstructor, std::invalid_argument);
	CPPUNIT_TEST_SUITE_END();


public:
	void setUp() override;
	void tearDown() override;

};


#endif //HASHTABLETEST_H
