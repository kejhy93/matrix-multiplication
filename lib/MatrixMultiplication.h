#ifndef __MATRIX_MULTIPLICATION_H__
#define __MATRIX_MULTIPLICATION_H__

#include <iostream>
#include "Matrix.h"

class MatrixMultiplication {

public:
	virtual ~MatrixMultiplication();


	virtual Matrix* multiply(const Matrix& left, const Matrix& right) = 0;

	static bool areMatricesCompatibleForMultiplication ( const Matrix& left, const Matrix& right);
};

#endif