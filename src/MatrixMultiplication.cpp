#include "MatrixMultiplication.h"

MatrixMultiplication::~MatrixMultiplication() {
	
}

/**
 * Verify that matrix multiplcation can be applied.
 * true if matrix multiplication can be applied
 * false otherwise
 */
bool MatrixMultiplication::areMatricesCompatibleForMultiplication ( const Matrix& left, const Matrix& right) {
	int colLeftMatrix, rowRightMatrix;

	colLeftMatrix = left.get_col();

	rowRightMatrix = right.get_row();

	return colLeftMatrix == rowRightMatrix;
}

/**
 * Linear combination
 * Calculate linear combination of left's row vector and right's column vector.
 */
double MatrixMultiplication::linear_combination ( const Matrix& left, const Matrix& right, const int& row, const int& col) 
{
	double sum = 0.0;
	for ( int index = 0 ; index < left.get_col() ; ++ index) {
		sum += left.get_value(row, index) * right.get_value(index, col);
	}
	return sum;
}