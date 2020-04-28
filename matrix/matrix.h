//
// Created by user on 31/03/2020.
//

#ifndef MATRIX_H
#define MATRIX_H

#include "errors.h"

//#define DEBUG

typedef struct bound
{
	unsigned start;
	unsigned finish;
	bound(unsigned st, unsigned f)
		: start(st), finish(f)
	{}
} bound_t;

namespace thr //this namespace means thr ~= threads
{

extern void parallel_matrix_multiplication(const bound_t *bd);

typedef struct cpu_data
{
	bound_t *bd_;
	unsigned cpu_; // on which logical processor to execute a thread
	cpu_data(bound_t *bd, unsigned cpu)
		: bd_(bd), cpu_(cpu)
	{ assert(bd_); } //just in case

} cpu_data_t;

#ifdef DEBUG
template<class T>
class matrix;

template <class T> std::ostream& operator<<(std::ostream& out, const matrix<T>& m);
#endif

template<class T>
class matrix
{
public:
#ifdef DEBUG
	friend std::ostream& operator<< <T> (std::ostream& out, const matrix<T>& m);
#endif

	friend void parallel_matrix_multiplication(const bound_t *bd);
	matrix(const matrix &m) = delete;
	~matrix();
	matrix &operator=(const matrix &m) = delete;
	matrix(matrix &&m) noexcept;
	matrix() = default;

	/*This is just a stupid serial algorithm for checking the corectness of the multiplication of matrices
	 * it is implemented as O(n^3)*/
	matrix operator*(const matrix<T> &m) const;
	bool operator==(const matrix<T> &m) const;

	void init_matrix(unsigned n, const T &value);

private :
	T **arr_;
	unsigned lines_ = 0;
	unsigned colomns_ = 0;
};

template<class T>
matrix<T>::matrix(matrix &&m) noexcept
	: arr_(m.arr_), lines_(m.lines_), colomns_(m.colomns_)
{
	m.arr_ = nullptr;
	m.lines_ = 0;
	m.colomns_ = 0;
}

template<class T>
bool matrix<T>::operator==(const matrix<T> &m) const
{
	if (this == &m)
		return true;

	if (lines_ != m.lines_ || colomns_ != m.colomns_)
		return false;

	for (unsigned i = 0; i < lines_; ++i) {
		for (unsigned j = 0; j < colomns_; ++j) {
			if (arr_[i][j] != m.arr_[i][j])
				return false;
		}
	}
	return true;
}

template<class T>
matrix<T> matrix<T>::operator*(const matrix<T> &m) const
{
	if (colomns_ != m.lines_)
		throw std::invalid_argument("this multiplication cannot be performed due to the bad matrices values");
	matrix<T> res;
	res.init_matrix(m.lines_, 0);
	T cur_val = 0;
	for (unsigned i = 0; i < lines_; ++i) {
		for (unsigned j = 0; j < m.colomns_; ++j) {
			for (unsigned ip = 0; ip < colomns_; ++ip)
				cur_val += arr_[i][ip] * m.arr_[ip][j];
			res.arr_[i][j] = cur_val;
			cur_val = 0;
		}

	}
	return res;
}

template<class T>
matrix<T>::~matrix()
{
	for (unsigned i = 0; i < lines_; ++i)
		delete[] arr_[i];
	delete[] arr_;
}

template<class T>
void matrix<T>::init_matrix(unsigned int n, const T &value)
{
	lines_ = n;
	colomns_ = n;
	arr_ = new T *[lines_];

	int i = 0;
	int rw = static_cast<int>(lines_);
	try {
		for (; i < rw; ++i) {
			arr_[i] = new T[colomns_];
			std::fill_n(arr_[i], colomns_, value);
		}
	}
	catch (...) {
		for (int down = (i - 1); down >= 0; --down)
			delete[] arr_[down];
		delete[] arr_;
		throw;
	}
}


#ifdef DEBUG
template <class T>
std::ostream& operator<<(std::ostream& out, const matrix<T>& m)
{
	for(size_t i = 0; i < m.lines_; ++i){
		for(size_t j = 0; j < m.colomns_; ++j){
			out << m.arr_[i][j] << " ";
		}
		out << std::endl;
	}
	return out;

}
#endif

} //namespace thr


#endif //MATRIX_H
