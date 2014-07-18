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
template<typename T> QSMatrix<T>& QSMatrix<T>::operator=(const QSMatrix<T>& rhs){
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
template<typename T> QSMatrix<T> QSMatrix<T>::operator+(const QSMatrix<T>& rhs){
	QSMatrix result(rows, cols, 0.0);

	for (unsigned i = 0; i < rows; i++){
		for (unsigned j = 0; j < cols; j++){
			result(i, j) = this->mat[i][j] + rhs(i, j);
		}
	}
	return result;
};

// Cumulative addition of two matrices
template<typename T> QSMatrix<T>& QSMatrix<T>::operator+=(const QSMatrix<T>& rhs){
	unsigned rows = rhs.get_rows();
	unsigned cols = rhs.get_cols();

	for (unsigned i = 0; i < rows; i++){
		for (unsigned j = 0; j < cols; j++){
			this->mat[i][j] += rhs(i, j);
		}
	}
	return *this;
};

// Subtraction of two matrices
template<typename T> QSMatrix<T> QSMatrix<T>::operator-(const QSMatrix<T>& rhs){
	unsigned rows = rhs.get_rows();
	unsigned cols = rhs.get_cols();
	QSMatrix result(rows, cols, 0.0);

	for (unsigned i = 0; i < rows; i++){
		for (unsigned j = 0; j < cols; j++){
			result(i,j) = this->mat[i][j] - rhs(i, j);
		}
	}
	return result;
};

// Cumulative subtraction of two matrices
template<typename T> QSMatrix<T>& QSMatrix<T>::operator-=(const QSMatrix<T>& rhs){
	unsigned rows = rhs.get_rows();
	unsigned cols = rhs.get_cols();

	for (unsigned i = 0; i < rows; i++){
		for (unsigned j = 0; j < cols; j++){
			this->mat[i][j] -= rhs(i, j);
		}
	}
	return *this;
};

// Left multiplication of this matrix and another
template<typename T> QSMatrix<T> QSMatrix<T>::operator*(const QSMatrix<T>& rhs){
	unsigned rows = rhs.get_rows();
	unsigned cols = rhs.get_cols();
	QSMatrix result(rows, cols, 0.0);

	for (unsigned i = 0; i < rows; i++){
		for (unsigned j = 0; j < cols; j++){
			for (unsigned k = 0; k < rows; k++){
				result(i, j) += this->mat[i][k] * rhs(k, j);
			}
		}
	}
	return result;
};

// CUmulative left multiplication of this matrix and another
template<typename T> QSMatrix<T>& QSMatrix<T>::operator*=(const QSMatrix<T>& rhs){
	QSMatrix result = (*this) * rhs;
	(*this) = result;
	return *this;
};
template<typename T> QSMatrix<T> QSMatrix<T>::transpose(){
	QSMatrix result(rows, cols, 0.0);

	for (unsigned i = 0; i < rows; i++){
		for (unsigned j = 0; j < cols; j++){
			result(i, j) = this->mat[j][i];
		}
	}
	return result;
};

// Scalar operations
template<typename T> QSMatrix<T> QSMatrix<T>::operator+(const T& rhs){
	QSMatrix result(rows, cols, 0.0);
	for (unsigned i = 0; i < rows; i++){
		for (unsigned j = 0; j < cols; j++){
			result(i, j) = this->mat[i][j] + rhs;
		}
	}
	return result;
};
template<typename T> QSMatrix<T> QSMatrix<T>::operator-(const T& rhs){
	QSMatrix result(rows, cols, 0.0);
	for (unsigned i = 0; i < rows; i++){
		for (unsigned j = 0; j < cols; j++){
			result(i, j) = this->mat[i][j] - rhs;
		}
	}
	return result;
};
template<typename T> QSMatrix<T> QSMatrix<T>::operator*(const T& rhs){
	QSMatrix result(rows, cols, 0.0);
	for (unsigned i = 0; i < rows; i++){
		for (unsigned j = 0; j < cols; j++){
			result(i, j) = this->mat[i][j] * rhs;
		}
	}
	return result;
};
template<typename T> QSMatrix<T> QSMatrix<T>::operator/(const T& rhs){
	QSMatrix result(rows, cols, 0.0);
	for (unsigned i = 0; i < rows; i++){
		for (unsigned j = 0; j < cols; j++){
			result(i, j) = this->mat[i][j] / rhs;
		}
	}
	return result;
};

// Matrix/vector operations
template<typename T> vector<T> QSMatrix<T>::operator*(const vector<T>& rhs){
	vector<T> result(rhs.size(), 0.0);

	for (unsigned i = 0; i < rows; i++){
		for (unsigned j = 0; j < cols; j++){
			result[i] = this->mat[i][j] * rhs[j];
		}
	}
	return result;
};

// Obtain vetor of all diagonal elements
template<typename T> vector<T> QSMatrix<T>::diag_vec(){
	vector<T> result(rows, 0.0);

	for (unsigned i = 0; i < rows; i++){
		result[i] = this->mat[i][i];
	}
	return result;
};

// Access all individual elements
template<typename T> T& QSMatrix<T>::operator() (const unsigned& row, const unsigned& col){
	return this->mat[row][col];
};
template<typename T> const T& QSMatrix<T>::operator()(const unsigned& row, const unsigned& col) const{
	return this->mat[row][col];
};

	// Access row and column sizes
template<typename T> unsigned QSMatrix<T>::get_rows() const{
	return this->rows;
};
template<typename T> unsigned QSMatrix<T>::get_cols() const{
	return this->cols;
};




#endif __QS_MATRIX_CPP__