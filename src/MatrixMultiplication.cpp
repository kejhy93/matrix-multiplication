#include "MatrixMultiplication.h"

bool MatrixMultiplication::areMatricesCompatibleForMultiplication ( const Matrix& left, const Matrix& right) {
	int colLeftMatrix, rowRightMatrix;

	colLeftMatrix = left.get_col();

	rowRightMatrix = right.get_row();

	return colLeftMatrix == rowRightMatrix;
}