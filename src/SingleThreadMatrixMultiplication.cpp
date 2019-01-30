#include "SingleThreadMatrixMultiplication.h"

Matrix* SingleThreadMatrixMultiplication::multiply ( const Matrix& left, const Matrix& right) {
	int rowLeftMatrix, colLeftMatrix, rowRightMatrix, colRightMatrix;

	std::cout << "[SingleThreadMatrixMultiplication]" << std::endl;

	rowLeftMatrix = left.get_row();
	colLeftMatrix = left.get_col();

	rowRightMatrix = right.get_row();
	colRightMatrix = right.get_col();

	bool areMatrixCompatibleForMultiplication = MatrixMultiplication::areMatricesCompatibleForMultiplication(left, right);

	if ( !areMatrixCompatibleForMultiplication ) {
		return nullptr;
	}

	int rowMultipliedMatrix = rowLeftMatrix;
	int colMultipliedMatrix = colRightMatrix;

	Matrix* finalMatrix = new Matrix(rowMultipliedMatrix, colMultipliedMatrix);
	// std::cout << "final matrix = [" << finalMatrix->get_row() << ";" << finalMatrix->get_col() << "]" << std::endl;

	for ( int rowCounter = 0 ; rowCounter < rowMultipliedMatrix ; ++ rowCounter ) {
		for ( int colCounter = 0 ; colCounter < colMultipliedMatrix ; ++ colCounter ) {
			double tmpSum = 0;
			for ( int index = 0 ; index < colLeftMatrix ; ++ index ) {
				// std::cout << "Row=" << rowCounter << ",Col=" << colCounter << ",Index=" << index << std::endl;
				tmpSum += left.get_value(rowCounter, index) * right.get_value(index, colCounter);
			}
			// std::cout << "set tmp_sum to [" << rowCounter << ";" << colCounter << "] = " << tmpSum << std::endl;
			finalMatrix->set_value(rowCounter, colCounter, tmpSum);
		}
	}

	return finalMatrix;
}