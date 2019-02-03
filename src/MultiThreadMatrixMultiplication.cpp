#include "MultiThreadMatrixMultiplication.h"

MultiThreadMatrixMultiplication::~MultiThreadMatrixMultiplication() {

}

Matrix* MultiThreadMatrixMultiplication::multiply ( const Matrix& left, const Matrix& right) {
    int rowLeftMatrix, colRightMatrix;

	std::cout << "[MultiThreadMatrixMultiplication]" << std::endl;

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
	std::cout << "final matrix = [" << finalMatrix->get_row() << ";" << finalMatrix->get_col() << "]" << std::endl;

    Executor* executor = new Executor(8);
    executor->execute ( left, right, *finalMatrix);

    delete executor;
	return finalMatrix;
}

double MultiThreadMatrixMultiplication::partiallyMatrixMultiplication ( const Matrix& left, const Matrix& right, const int& row, const int& col) {
    return 1.0;
}