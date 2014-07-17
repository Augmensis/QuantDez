#pragma once
#include "stdafx.h"
#ifndef __QS_MATRIX_CPP__
#define __QS_MATRIX_CPP__
//#include <vector>
using std::vector;

template <typename T> class QSMatrix {

private:

	vector<vector<T>> mat;	// Use a Vector of Vectors to store the values
	unsigned rows;
	unsigned cols;

public:

	QSMatrix(unsigned _rows, unsigned _cols, const T& _initial);
	QSMatrix(const QSMatrix<T>& rhs);
	virtual ~QSMatrix();

	// Basic Maths Operations
	QSMatrix<T>& operator=(const QSMatrix<T>& rhs);
	QSMatrix<T> operator+(const QSMatrix<T>& rhs);
	QSMatrix<T>& operator+=(const QSMatrix<T>& rhs);
	QSMatrix<T> operator-(const QSMatrix<T>& rhs);
	QSMatrix<T>& operator-=(const QSMatrix<T>& rhs);
	QSMatrix<T> operator*(const QSMatrix<T>& rhs);
	QSMatrix<T>& operator*=(const QSMatrix<T>& rhs);
	QSMatrix<T> transpose();

	// Scalar operations
	QSMatrix<T> operator+(const T& rhs);
	QSMatrix<T> operator-(const T& rhs);
	QSMatrix<T> operator*(const T& rhs);
	QSMatrix<T> operator/(const T& rhs);

	// Matrix/vector operations
	vector<T> operator*(const vector<T>& rhs);
	vector<T> diag_vec();

	// Access all individual elements
	T& operator() (const unsigned& row, const unsigned& col);
	const T& operator()(const unsigned& row, const unsigned& col) const;

	// Access row and column sizes
	unsigned get_rows() const;
	unsigned get_cols() const;

};


#endif __QS_MATRIX_CPP__