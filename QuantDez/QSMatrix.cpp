#pragma once
#include "stdafx.h"
#ifndef __QS_MATRIX_CPP__
#define __QS_MATRIX_CPP__
//#include <vector>
using std::vector;

// Parameter constructor
template<typename T> QSMatrix<T>::QSMatrix(unsigned _rows, unsigned _cols, const T& _initial){
	mat.resize(_rows);
	for (unsigned i = 0; i < mat.size(); i++){
		mat[i].resize(_cols, _initial);
	}

	rows = _rows;
	cols = _cols;
};

// Copy constructor
template<typename T> QSMatrix<T>::QSMatrix(const QSMatrix<T>& rhs){
	mat = rhs.mat;
	rows = rhs.get_rows;
	cols = rhs.get_cols;
};

// Virtual destructor
template<typename T> QSMatrix<T>::~QSMatrix(){};


// Basic Maths Operations
//+++++++++++++++++++++++++

// Assignment operator
template<typename T> QSMatrix<T>::QSMatrix<T>& operator=(const QSMatrix<T>& rhs){
	if (&rhs == this) return *this;

	unsigned new_rows = rhs.get_rows();
	unsigned new_cols = rhs.get_cols();

	mat.resize(new_rows);
	for (unsigned i = 0; i < mat.size(); i++){
		mat[i].resize(new_cols);
	}

	for (unsigned i = 0; i < new_rows; i++){
		for (unsigned j = 0; j < new_cols; j++) {
			mat[i][j] = rhs(i, j);
		}
	}

	rows = new_rows;
	cols = new_cols;

	return *this;
};

// Addition of two matrices
template<typename T> QSMatrix<T>::QSMatrix<T> operator+(const QSMatrix<T>& rhs){
	QSMatrix result(rows, cols, 0.0);

	for (unsigned i = 0; i < rows; i++){
		for (unsigned j = 0; j < cols; j++){
			result(i, j) = this->mat[i][j] + rhs(i, j);
		}
	}
	return result;
};

// Cumulative addition of two matrices
template<typename T> QSMatrix<T>::QSMatrix<T>& operator+=(const QSMatrix<T>& rhs){
	unsigned rows = rhs.get_rows();
	unsigned cols = rhs.get_cols();

	for (unsigned i = 0; i < rows; i++){
		for (unsigned j = 0; j < cols; j++){
			this->mat[i][j] += rhs(i, j);
		}
	}
	return *this;
};
template<typename T> QSMatrix<T>::QSMatrix<T> operator-(const QSMatrix<T>& rhs){
	QSMatrix result(rows, cols, 0.0);

	for (unsigned i = 0; i < rows; i++){
		for (unsigned j = 0; j < cols; j++){
			this->mat[i][j] - rhs(i, j);
		}
	}
	return *this;
};
template<typename T> QSMatrix<T>::QSMatrix<T>& operator-=(const QSMatrix<T>& rhs){
	unsigned rows = rhs.get_rows();
	unsigned cols = rhs.get_cols();

	for (unsigned i = 0; i < rows; i++){
		for (unsigned j = 0; j < cols; j++){
			this->mat[i][j] -= rhs(i, j);
		}
	}
	return *this;
};
template<typename T> QSMatrix<T>::QSMatrix<T> operator*(const QSMatrix<T>& rhs);
template<typename T> QSMatrix<T>::QSMatrix<T>& operator*=(const QSMatrix<T>& rhs);
template<typename T> QSMatrix<T>::QSMatrix<T> transpose();

	// Scalar operations
template<typename T> QSMatrix<T>::QSMatrix<T> operator+(const T& rhs);
template<typename T> QSMatrix<T>::QSMatrix<T> operator-(const T& rhs);
template<typename T> QSMatrix<T>::QSMatrix<T> operator*(const T& rhs);
template<typename T> QSMatrix<T>::QSMatrix<T> operator/(const T& rhs);

	// Matrix/vector operations
template<typename T> QSMatrix<T>::vector<T> operator*(const vector<T>& rhs);
template<typename T> QSMatrix<T>::vector<T> diag_vec();

	// Access all individual elements
template<typename T> QSMatrix<T>::T& operator() (const unsigned& row, const unsigned& col);
template<typename T> QSMatrix<T>::const T& operator()(const unsigned& row, const unsigned& col) const;

	// Access row and column sizes
template<typename T> QSMatrix<T>::unsigned get_rows() const;
template<typename T> QSMatrix<T>::unsigned get_cols() const;




#endif __QS_MATRIX_CPP__