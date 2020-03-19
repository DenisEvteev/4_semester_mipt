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
	using map = std::multimap<std::size_t, int>;

	static void testConstructorThrow();
	static void testRedefineAllocOpers();
	static void testInsertElement();
	static void testInsertBigAmountAndErase();
	static void testIncrementDecrementOperators();
	static void testOperatorDumpingIntoFile();
	static void testCopyConstructorAssignmentOperator();
	static void testEasyCoverage();
private :
CPPUNIT_TEST_SUITE(hashTableTest);
		CPPUNIT_TEST(testInsertElement);
		CPPUNIT_TEST(testInsertBigAmountAndErase);
		CPPUNIT_TEST(testCopyConstructorAssignmentOperator);
		CPPUNIT_TEST(testIncrementDecrementOperators);
		CPPUNIT_TEST(testOperatorDumpingIntoFile);
		CPPUNIT_TEST(testEasyCoverage);
		CPPUNIT_TEST_EXCEPTION(testRedefineAllocOpers, std::runtime_error);
		CPPUNIT_TEST_EXCEPTION(testConstructorThrow, std::bad_alloc);
	CPPUNIT_TEST_SUITE_END();


public:
	void setUp() override;
	void tearDown() override;

};


#endif //HASHTABLETEST_H
