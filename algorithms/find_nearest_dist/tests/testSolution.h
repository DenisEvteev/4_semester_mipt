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


class testSolution: public CppUnit::TestFixture
{

	static void AllPointsOnOneVerticalLine();
	static void TheSamePoint();
	static void AllPointsOnOneHorizontalLine();
	static void testFromBrother();
	static void MinimalDistanceNotFromHalves();
	static void testSquareWithAPointInside();

CPPUNIT_TEST_SUITE(testSolution);
		CPPUNIT_TEST(AllPointsOnOneVerticalLine);
		CPPUNIT_TEST(AllPointsOnOneHorizontalLine);
		CPPUNIT_TEST(testFromBrother);
		CPPUNIT_TEST(TheSamePoint);
		CPPUNIT_TEST(MinimalDistanceNotFromHalves);
		CPPUNIT_TEST(testSquareWithAPointInside);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();

};


#endif //TESTSOLUTION_H
