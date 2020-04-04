//
// Created by user on 04/04/2020.
//

#ifndef TESTSOLUTION_H
#define TESTSOLUTION_H

#include "../Solution.h"
#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/Test.h>
#include <cppunit/TestCaller.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

#define RANDOM_VALUE(bound) ( 2 * ( std::rand() % ( bound ) ) - ( bound ) )

class testSolution: public CppUnit::TestFixture
{

	static void AllPointsOnOneVerticalLine();
	static void TheSamePoint();
	static void AllPointsOnOneHorizontalLine();
	static void testFromBrother();
	static void MinimalDistanceNotFromHalves();
	static void testSquareWithAPointInside();
	/*This test will check the work of the application with the biggest allowed number of points
	 * In the condition of the task we were said about n = 10^5*/
	static void testBigData();
	static void testSinglePairPoints();
	static void testMinimalDistInLeftPart();

CPPUNIT_TEST_SUITE(testSolution);
		CPPUNIT_TEST(AllPointsOnOneVerticalLine);
		CPPUNIT_TEST(AllPointsOnOneHorizontalLine);
		CPPUNIT_TEST(testFromBrother);
		CPPUNIT_TEST(TheSamePoint);
		CPPUNIT_TEST(MinimalDistanceNotFromHalves);
		CPPUNIT_TEST(testSquareWithAPointInside);
		CPPUNIT_TEST(testBigData);
		CPPUNIT_TEST(testSinglePairPoints);
		CPPUNIT_TEST(testMinimalDistInLeftPart);

	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

};


#endif //TESTSOLUTION_H
