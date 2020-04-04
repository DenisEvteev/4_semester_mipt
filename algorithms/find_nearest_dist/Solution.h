//
// Created by user on 03/04/2020.
//

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include "merge.hpp"
#include <climits>
#include <functional>
#include <cmath>


namespace dot
{

enum
{
	BASIC_CASE = 3,
	MAXIMUM_ELEMENTS = 8
};

class Solution
{
public:
	Solution() = default;
	Solution(const Solution &rhs) = delete;
	Solution &operator=(const Solution &rhs) = delete;
	friend std::istream &operator>>(std::istream &in, Solution &rhs);
	friend std::ostream &operator<<(std::ostream &out, const Solution &rhs);
	int find_nearest_dist();
	struct Point
	{
		int x_ = 0;
		int y_ = 0;
		Point(int x, int y)
			: x_(x), y_(y)
		{}
		Point() = default;
		Point(const Point &p) = default;
	};
	explicit Solution(std::vector<Point> &&vec);
	int get_n() const
	{ return n_; }
	int get_y(size_t i) const
	{ return dots[i].y_; }

private :
	/*Left and right are respond to the left and to the right index in dots vector to conquer*/
	int find_min(size_t start, size_t end);
	int merge_minimal(int middle_x_c, int cur_min, size_t start, size_t mid);

	size_t n_ = 0;
	std::vector<Point> dots;
	int square_distance(const Point &p1, const Point &p2) const;
	int basic_case(size_t start, size_t end);

};

} // namespace dot

template<>
struct std::less<dot::Solution::Point>
{
	bool operator()(const dot::Solution::Point &p1, const dot::Solution::Point &p2) const;
};


#endif //SOLUTION_H
