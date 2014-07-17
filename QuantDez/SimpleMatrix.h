#pragma once
#include "stdafx.h"
#ifndef __SIMPLE_MATRIX_H__
#define __SIMPLE_MATRIX_H__

template <typename Type = double> class SimpleMatrix {

private:

	std::vector<std::vector<Type> > mat;	// Use a Vector of Vectors to store the values

public:

	SimpleMatrix();
	
	// Rows, cols and default value
	SimpleMatrix(const int& rows, const int& cols, const Type& val);

	// Copy constructor
	SimpleMatrix(const SimpleMatrix<Type>& _rhs); 

	SimpleMatrix<Type>& operator= (const SimpleMatrix<Type>& _rhs);

	virtual ~SimpleMatrix();

	// Direct access to matrix values
	std::vector<std::vector<Type> > get_mat() const;
	Type& value(const int& row, const int& col);

};


#endif __SIMPLE_MATRIX_H__