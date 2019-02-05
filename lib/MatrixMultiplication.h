#ifndef __MATRIX_MULTIPLICATION_H__
#define __MATRIX_MULTIPLICATION_H__

#include <iostream>
#include "Matrix.h"

class MatrixMultiplication {

public:
	virtual ~MatrixMultiplication();


	virtual Matrix* multiply(const Matrix& left, const Matrix& right) = 0;

	/**
 	 * Verify that matrix multiplcation can be applied.
 	 * true if matrix multiplication can be applied, false otherwise
 	 */
	static bool areMatricesCompatibleForMultiplication ( const Matrix& left, const Matrix& right);

	/**
 	 * Linear combination
 	 */
	static double linear_combination ( const Matrix& left, const Matrix& right, const int& row, const int& col);
};

#endif