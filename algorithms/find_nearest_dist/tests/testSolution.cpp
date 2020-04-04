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
		vec.emplace_back(common_x, 3 * i);
	}
	dot::Solution sl1(std::move(vec));
	CPPUNIT_ASSERT(sl1.get_n() == 1000);
	CPPUNIT_ASSERT_EQUAL(static_cast<int>(9), sl1.find_nearest_dist());
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
	CPPUNIT_ASSERT_EQUAL(static_cast<int>(0), sl1.find_nearest_dist());
}

void testSolution::AllPointsOnOneHorizontalLine()
{
	std::vector<dot::Solution::Point> vec;
	int common_y = 3802;
	for (int i = -2000; i < 2000; ++i) {
		vec.emplace_back(i * 2, common_y);
	}
	dot::Solution sl1(std::move(vec));
	CPPUNIT_ASSERT_EQUAL(static_cast<int>(4000), sl1.get_n());
	CPPUNIT_ASSERT_EQUAL(static_cast<int>(4), sl1.find_nearest_dist());
}

void testSolution::testFromBrother()
{

	std::vector<dot::Solution::Point> vec = {{2, 3}, {7, 3}, {4, 3}, {5, 4}, {4, 5}, {5, 1}, {5, 6},
											 {6, 3}, {2, 5}};
	dot::Solution sl1(std::move(vec));
	CPPUNIT_ASSERT_EQUAL(static_cast<int>(1), sl1.find_nearest_dist());
}

void testSolution::MinimalDistanceNotFromHalves()
{
	std::vector<dot::Solution::Point> vec = {
		{4, 3}, {2, 1}, {6, 5}, {7, 5}, {2, 3}, {9, 3}, {100, 10000}, {-1000, -1000}
	};
	dot::Solution sl1(std::move(vec));
	CPPUNIT_ASSERT_EQUAL(static_cast<int>(1), sl1.find_nearest_dist());
}

void testSolution::testSquareWithAPointInside()
{
	std::vector<dot::Solution::Point> vec = {
		{0, 0}, {1, -1}, {-1, 1}, {-1, -1}, {1, 1}
	};
	dot::Solution sl1(std::move(vec));
	CPPUNIT_ASSERT_EQUAL(static_cast<int>(2), sl1.find_nearest_dist());
}