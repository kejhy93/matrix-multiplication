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
		std::cerr << "Given matrices are not compatible to multiple." << std::endl;
		return new Matrix(0,0);
	}

	int rowMultipliedMatrix = rowLeftMatrix;
	int colMultipliedMatrix = colRightMatrix;

	Matrix* finalMatrix = new Matrix(rowMultipliedMatrix, colMultipliedMatrix);
	// std::cout << "final matrix = [" << finalMatrix->get_row() << ";" << finalMatrix->get_col() << "]" << std::endl;

	for ( int rowCounter = 0 ; rowCounter < rowMultipliedMatrix ; ++ rowCounter) {
		for ( int colCounter = 0 ; colCounter < colMultipliedMatrix ; ++ colCounter ) {
			double partiallyResult = this->partiallyMatrixMultiplication ( left, right, rowCounter, colCounter);

			finalMatrix->set_value(rowCounter, colCounter, partiallyResult);
		}
	}
	return finalMatrix;
}

double SingleThreadMatrixMultiplication::partiallyMatrixMultiplication ( const Matrix& left, const Matrix& right, const int& row, const int& col) {
	double sum = 0.0;
	for ( int index = 0 ; index < left.get_col() ; ++ index ) {
		sum += left.get_value(row, index) * right.get_value(index, col);
	}
	return sum;
}