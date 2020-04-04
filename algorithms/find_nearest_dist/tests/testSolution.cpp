//
// Created by user on 04/04/2020.
//

#include "testSolution.h"


void testSolution::setUp()
{}
void testSolution::tearDown()
{}

void testSolution::AllPointsOnOneVerticalLine()
{
	std::vector<dot::Solution::Point> vec;
	int common_x = 3802;
	for (size_t i = 0; i < 1000; ++i) {
		vec.emplace_back(common_x, static_cast<int>(3 * i));
	}
	dot::Solution sl1(std::move(vec));
	CPPUNIT_ASSERT(sl1.get_n() == 1000);
	CPPUNIT_ASSERT_EQUAL(static_cast<long>(9), sl1.find_nearest_dist());
	/*Also I would like to check whether all the elements in sl1 are sorted by y coordinate in ascending order*/
	for (int i = 1; i < sl1.get_n(); ++i) {
		CPPUNIT_ASSERT(sl1.get_y(i - 1) <= sl1.get_y(i));
	}
}

void testSolution::TheSamePoint()
{
	std::vector<dot::Solution::Point> vec;
	int common_p = 3802;
	for (size_t i = 0; i < 5000; ++i) {
		vec.emplace_back(common_p, common_p);
	}
	dot::Solution sl1(std::move(vec));
	CPPUNIT_ASSERT_EQUAL(static_cast<long>(0), sl1.find_nearest_dist());
}

void testSolution::AllPointsOnOneHorizontalLine()
{
	std::vector<dot::Solution::Point> vec;
	int common_y = 3802;
	for (int i = -2000; i < 2000; ++i) {
		vec.emplace_back(static_cast<int>(i * 2), common_y);
	}
	dot::Solution sl1(std::move(vec));
	CPPUNIT_ASSERT_EQUAL(static_cast<int>(4000), sl1.get_n());
	CPPUNIT_ASSERT_EQUAL(static_cast<long>(4), sl1.find_nearest_dist());
}

void testSolution::testFromBrother()
{

	std::vector<dot::Solution::Point> vec = {{2, 3}, {7, 3}, {4, 3}, {5, 4}, {4, 5}, {5, 1}, {5, 6},
											 {6, 3}, {2, 5}};
	dot::Solution sl1(std::move(vec));
	CPPUNIT_ASSERT_EQUAL(static_cast<long>(1), sl1.find_nearest_dist());
}

void testSolution::MinimalDistanceNotFromHalves()
{
	std::vector<dot::Solution::Point> vec = {
		{4, 3}, {2, 1}, {6, 5}, {7, 5}, {2, 3}, {9, 3}, {100, 10000}, {-1000, -1000}
	};
	dot::Solution sl1(std::move(vec));
	CPPUNIT_ASSERT_EQUAL(static_cast<long>(1), sl1.find_nearest_dist());
}

void testSolution::testSquareWithAPointInside()
{
	std::vector<dot::Solution::Point> vec = {
		{0, 0}, {1, -1}, {-1, 1}, {-1, -1}, {1, 1}
	};
	dot::Solution sl1(std::move(vec));
	CPPUNIT_ASSERT_EQUAL(static_cast<long>(2), sl1.find_nearest_dist());
}

void testSolution::testBigData()
{
	std::vector<dot::Solution::Point> vec;
	int the_max_bound = 100000;
	vec.reserve(the_max_bound);
	for (int i = 0; i < (the_max_bound - 2); ++i) {
		vec.emplace_back(static_cast<int>(RANDOM_VALUE(the_max_bound)), static_cast<int>(RANDOM_VALUE(the_max_bound)));
	}
	vec.emplace_back(-1, -1);
	vec.emplace_back(-1, 0);
	dot::Solution sl1(std::move(vec));
	CPPUNIT_ASSERT_EQUAL(static_cast<int>(the_max_bound), sl1.get_n());
	CPPUNIT_ASSERT_EQUAL(static_cast<long>(1), sl1.find_nearest_dist());
}

void testSolution::testSinglePairPoints()
{
	dot::Solution sl1(std::vector<dot::Solution::Point>{{-99996, -7228}, {-99994, -93930}});
	CPPUNIT_ASSERT_EQUAL(static_cast<int>(2), sl1.get_n());
	CPPUNIT_ASSERT_EQUAL(static_cast<long>(7517236808), sl1.find_nearest_dist());
}

void testSolution::testMinimalDistInLeftPart()
{
	std::vector<dot::Solution::Point> vec{
		{0, 0}, {8, 0}, {9, 1}, {2, 0}, {3, 0}, {2, 2}, {5, 3}, {7, 3}, {6, 4}
	};
	dot::Solution sl1(std::move(vec));
	CPPUNIT_ASSERT_EQUAL(static_cast<long>(1), sl1.find_nearest_dist());
}

