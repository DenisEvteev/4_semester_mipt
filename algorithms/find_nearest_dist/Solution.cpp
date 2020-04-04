//
// Created by user on 03/04/2020.
//

#include "Solution.h"


using namespace dot;


namespace dot
{


Solution::Solution(std::vector<Point> &&vec)
	: n_(vec.size()), dots(std::move(vec))
{}

std::istream &operator>>(std::istream &in, Solution &rhs)
{
	assert(in.good());
	in >> rhs.n_;
	assert(rhs.n_ > 0);
	assert(in.good());
	rhs.dots.reserve(rhs.n_);

	int x{0}, y{0};
	for (size_t i = 0; i < rhs.n_; ++i) {
		in >> x;
		in >> y;
		assert(in.good());
		rhs.dots.emplace_back(x, y);
	}

	return in;
}

std::ostream &operator<<(std::ostream &out, const Solution &rhs)
{
	assert(rhs.n_ > 0);
	for (size_t i = 0; i < rhs.n_; ++i) {
		out << "[ " << rhs.dots[i].x_ << "; " << rhs.dots[i].y_ << " ]" << std::endl;
		assert(out.good());
	}
	return out;
}

int Solution::find_min(size_t start, size_t end)
{

	/*Preserve the middle X coordinate in sorted by x in ascending order array of points [dots]
	 * This integer value is necessary in my implementation due to the basic at the end action
	 * sort the part of dots by Y coordinate in ascending order so we forget the major middle element
	 * which is required in merge_minimal method to find the least element between cur_min and distance which
	 * are between neighbour points*/

	int middle_x_coordinate = dots[(end - start) / 2].x_;
	/* The basic case must work with a constant time O(1), so I consider it as
	 * three elements starting with index [start] and finishing with [end].
	 * the general count of elements [end - start + 1] in basic case should be less or equal than 3
	 * In this case we just find minimal distance using O(n^2) algorithm*/

	if ((end - start + 1) <= BASIC_CASE)
		return basic_case(start, end);

	int bound = static_cast<size_t>((end - start) / 2 );
	int min_l = find_min(start, start + bound);
	int min_r = find_min(start + bound + 1, end);
	int cur_min = std::min(min_l, min_r);
	int min = merge_minimal(middle_x_coordinate, cur_min, start, end);

	return std::min(min, cur_min);

}

int Solution::merge_minimal(int middle_x_c, int cur_min, size_t start, size_t end)
{
	assert(cur_min >= 0);
	merge(dots, start, end, std::less<Point>());

	auto g_size{end - start + 1};
	/*We should remember that cur_min it's a minimal square_distance between points --- So I should remember this fact
	 * and compare position of points depending on this fact*/
	int minimal{cur_min};
	std::vector<Point> right_coordinates; // this vector need only constant size, so the memory usage is O(1)

	right_coordinates.reserve(MAXIMUM_ELEMENTS);
	auto mid_x = static_cast<double>(middle_x_c);
	for (size_t i = 0; i < g_size; ++i) {
		/*I work only with points which are situated in the rectangle of size : [cur_min; 2 * cur_min]*/
		if (static_cast<double>( dots[start + i].x_ ) < (mid_x - std::sqrt(cur_min)) ||
			static_cast<double>( dots[start + i].x_ ) > (mid_x + std::sqrt(cur_min)))
			continue;
		for (int down = (right_coordinates.size() - 1); down >= 0; --down) {
			if ((right_coordinates[down].y_ <= dots[start + i].y_) &&
				(static_cast<double>( dots[start + i].y_ - right_coordinates[down].y_ )) <= std::sqrt(cur_min)) {
				minimal = std::min(minimal, square_distance(right_coordinates[down], dots[start + i]));
			}
		}
		right_coordinates.push_back(dots[start + i]);
	}

	return minimal;
}

int Solution::find_nearest_dist()
{
	std::sort(dots.begin(), dots.end(), [](const Point &p1, const Point &p2)
	{ return (p1.x_ < p2.x_); });

	return find_min(0, (dots.size() - 1));
}

int Solution::square_distance(const Point &p1, const Point &p2) const
{
	return ((p2.x_ - p1.x_) * (p2.x_ - p1.x_) + (p2.y_ - p1.y_) * (p2.y_ - p1.y_));
}

int Solution::basic_case(size_t start, size_t end)
{
	int dist{0},
		min_dist{INT_MAX}; // at the condition of the task we were talked that the max value for a coordinate is 10^5
	for (size_t i = 0; i < (end - start + 1); ++i) {
		for (size_t ip = (i + 1); ip < (end - start + 1); ++ip) {
			dist = square_distance(dots[start + i], dots[start + ip]);
			min_dist = std::min(dist, min_dist);
		}
	}

	std::sort(std::next(dots.begin(), start), ++std::next(dots.begin(), end),
			  [](const Point &p1, const Point &p2)
			  { return p1.y_ < p2.y_; });
	return min_dist;
}

} //namespace dot


bool std::less<Solution::Point>::operator()(const Solution::Point &p1, const Solution::Point &p2) const
{
	return (p1.y_ < p2.y_);
}