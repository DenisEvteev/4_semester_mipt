//
// Created by user on 03/04/2020.
//

#ifndef MERGE_HPP
#define MERGE_HPP

#include <vector>
#include <functional>

template<class T, class Comp>
void merge(std::vector<T> &res, size_t start, size_t end, const Comp &comp)
{
	/*Work with the situation when we have only two elements
	 * I will manage it in more easy way without allocating any additional memory for vectors*/
	size_t mid = start + static_cast<size_t>((end - start) / 2 ) + 1;

	if (end == mid && (end - start == 1)) {
		if (comp(res[end], res[start]))
			std::swap(res[start], res[end]);
		return;
	}
	std::vector<T> left, right;
	auto middle{res.begin() + mid};
	std::copy((res.begin() + start),
			  middle,
			  std::back_inserter(left)); // we are have filled the left vector with left part of res vector
	std::copy(middle,
			  (res.begin() + end + 1),
			  std::back_inserter(right)); // we are have filled the right vector with right part of res vector

	size_t count_left{0};
	size_t count_right{0};
	size_t ip{0};
	size_t g_size{left.size() + right.size()};
	while (ip < g_size) {
		if (count_right == right.size() ||
			(count_left != left.size() && comp(left[count_left], right[count_right]))) {
			res[start + ip] = left[count_left];
			++count_left;
			++ip;
			continue;
		}
		res[start + ip] = right[count_right];
		++ip;
		++count_right;
	}

}


#endif //MERGE_HPP
