//
// Created by user on 31/03/2020.
//

#ifndef MATRIX_H
#define MATRIX_H


#include "errors.h"

namespace thr //this namespace means thr ~= threads
{


struct bound
{
	unsigned row_s = 0;
	unsigned row_f = 0;
	unsigned col_s = 0;
	unsigned col_f = 0;
};

template<class T>
class matrix;

#ifdef DEBUG
template <class T> std::ostream& operator<<(std::ostream& out, const matrix<T>& m);
#endif

template<class T>
class matrix
{
public:
#ifdef DEBUG
	friend std::ostream& operator<< <T> (std::ostream& out, const matrix<T>& m);
#endif

	matrix(const matrix &m) = delete;
	~matrix();
	matrix &operator=(const matrix &m) = delete;
	matrix(matrix &&m) noexcept;
	matrix() = default;
	void make_arr(unsigned lines, unsigned colomns);
	unsigned get_lines() const noexcept
	{ return lines_; }
	void set_arr(unsigned row, unsigned col, T value)
	{ arr_[row][col] = value; }
	T get_arr(unsigned row, unsigned col) const noexcept
	{ return arr_[row][col]; }
	/*This is just a stupid serial algorithm for checking the corectness of the multiplication of matrices
	 * it is implemented as O(n^3)*/
	matrix operator*(const matrix<T> &m) const noexcept;
	bool operator==(const matrix<T> &m) const noexcept;

private :
	T **arr_ = nullptr;
	unsigned lines_ = 0;
	unsigned colomns_ = 0;
};

template<class T>
matrix<T>::matrix(matrix &&m) noexcept
	: arr_(m.arr_), lines_(m.lines_), colomns_(m.colomns_)
{
	arr_ = nullptr;
	lines_ = 0;
	colomns_ = 0;
}

template<class T>
bool matrix<T>::operator==(const matrix<T> &m) const noexcept
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
matrix<T> matrix<T>::operator*(const matrix<T> &m) const noexcept
{
	if (colomns_ != m.lines_)
		throw std::invalid_argument("this multiplication cannot be performed due to the bad matrices values");
	matrix<T> res;
	res.make_arr(lines_, m.colomns_);
	for (unsigned i = 0; i < lines_; ++i) {
		for (unsigned j = 0; j < m.colomns_; ++j) {
			res.arr_[i][j] = 0;
			for (unsigned ip = 0; ip < colomns_; ++ip)
				res.arr_[i][j] += arr_[i][ip] * m.arr_[ip][j];
		}
	}
	return res;
}

template<class T>
void matrix<T>::make_arr(unsigned int lines, unsigned int colomns)
{
	lines_ = lines;
	colomns_ = colomns;
	arr_ = new T *[lines_];

	unsigned i = 0;
	try {
		for (; i < lines_; ++i) {
			arr_[i] = new T[colomns_]{0};
		}
	}
	catch (...) {
		for (int down = (i - 1); down >= 0; --down)
			delete[] arr_[down];
		delete[] arr_;
		throw;
	}
}

template<class T>
matrix<T>::~matrix()
{
	for (unsigned i = 0; i < lines_; ++i) {
		delete[] arr_[i];
	}
	delete[] arr_;
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
