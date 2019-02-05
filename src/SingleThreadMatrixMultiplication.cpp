#include "SingleThreadMatrixMultiplication.h"

SingleThreadMatrixMultiplication::~SingleThreadMatrixMultiplication() {
	
}

Matrix* SingleThreadMatrixMultiplication::multiply ( const Matrix& left, const Matrix& right) {
	int rowLeftMatrix, colRightMatrix;

	std::cout << "[SingleThreadMatrixMultiplication]" << std::endl;

	rowLeftMatrix = left.get_row();
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
			double partiallyResult = MatrixMultiplication::linear_combination( left, right, rowCounter, colCounter);

			finalMatrix->set_value(rowCounter, colCounter, partiallyResult);
		}
	}
	return finalMatrix;
}