//
// Created by user on 01/04/2020.
//

#include <vector>
#include <iostream>

#include "merge.hpp"

template <class T>
void merge_sort(std::vector<T>& res, size_t start, size_t end);


int main()
{
	std::vector<int> v{3, 41, 52, 26, 38, 57, 9, 49};

	/*This function should sort my vector with the increase order*/
	merge_sort(v, 0, v.size() - 1);

	for(int i = 0; i < v.size(); ++i){
		std::cout << v[i] << std::endl;
	}
	return 0;
}

template <class T>
void merge_sort(std::vector<T>& res, size_t start, size_t end){
	if(res.empty())
		return;
	if(start == end) // the case of a single element
		return;

	merge_sort(res, start, start + static_cast<size_t>( (end - start) / 2 ) );
	merge_sort(res, start + static_cast<size_t>( (end - start) / 2 ) + 1, end);
	merge(res, start, end, std::less<int>());
}

