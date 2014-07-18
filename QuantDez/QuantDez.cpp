// QuantDez.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, _TCHAR* argv[])
{
	QSMatrix<double> matrix1(100, 100, 7.4);
	QSMatrix<double> matrix2(100, 100, 2.1);
	QSMatrix<double> matrix3 = matrix1 * matrix2;



	for (int i = 0; i < matrix3.get_rows(); i++){
		for (int j = 0; j < matrix3.get_cols(); j++){
			std::cout << matrix3(i, j) << ", ";
		}
		std::cout << std::endl;
	}

	std::cin.ignore();

	return 0;
}

