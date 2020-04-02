//
// Created by user on 01/04/2020.
//

#include <vector>
#include <iostream>

template <class T>
void merge_sort(std::vector<T>& res, size_t start, size_t end);

template <class T>
void merge(std::vector<T>& res, size_t start, size_t mid, size_t end);



int main()
{
	std::vector<int> v(5000);
	for(int i = 0; i < v.size(); ++i){
		v[i] = std::rand();
	}
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
	merge(res, start, start + static_cast<size_t>( (end - start) / 2 ) + 1, end);
}

template<class T>
void merge(std::vector<T>& res, size_t start, size_t mid, size_t end){
	/*Work with the situation when we have only two elements
	 * I will manage it in more easy way without allocating any additional memory for vectors*/
	if( end == mid && (end - start == 1) )
	{
		if(res[start] > res[end])
			std::swap(res[start], res[end]);
		return;
	}
	std::vector<T> left, right;
	typename std::vector<T>::iterator middle{res.begin() + mid};
	std::copy( ( res.begin() + start ), middle, std::back_inserter(left)); // we are have filled the left vector with left part of res vector
	std::copy(middle, ( res.begin() + end + 1 ) , std::back_inserter(right)); // we are have filled the right vector with right part of res vector

	size_t count_left{0};
	size_t count_right{0};
	size_t ip{0};
	size_t g_size{left.size() + right.size()};
	while(ip < g_size)
	{
		if( count_right == right.size() || ( count_left != left.size() && left[count_left] <= right[count_right]))
		{
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
