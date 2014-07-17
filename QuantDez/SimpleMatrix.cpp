#pragma once
#include "stdafx.h"
#ifndef __SIMPLE_MATRIX_CPP__
#define __SIMPLE_MATRIX_CPP__

template <typename Type> SimpleMatrix<Type>::SimpleMatrix(){};	// Vector "mat" will create default storage

template <typename Type> SimpleMatrix<Type>::SimpleMatrix(const int& rows, const int& cols, const Type& val){
	for (int i = 0; i < rows; i++){
		std::vector<Type> col_vec(cols, val);
		mat.push_back(col_vec);
	}
}

template <typename Type> SimpleMatrix<Type>::SimpleMatrix(const SimpleMatrix<Type>& _rhs){
	mat = _rhs.get_mat();
}

template <typename Type> SimpleMatrix<Type>& SimpleMatrix<Type>::operator= (const SimpleMatrix<Type>& _rhs){
	if (this == &_rhs) return *this;

	mat = _rhs.get_mat();
	return *this;
}

template <typename Type> SimpleMatrix<Type>::~SimpleMatrix(){}

template <typename Type> std::vector<std::vector<Type>> SimpleMatrix<Type>::get_mat() const {
	return mat;
}

template <typename Type> SimpleMatrix<Type> SimpleMatrix<Type>::get_mat() const {
	return mat;
}

template <typename Type> Type& SimpleMatrix<Type>::value(const int& row, const int& col) {
	return mat[row][col];
}


#endif __SIMPLE_MATRIX_CPP__