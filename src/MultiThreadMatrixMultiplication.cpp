#include "MultiThreadMatrixMultiplication.h"

MultiThreadMatrixMultiplication::MultiThreadMatrixMultiplication( const int thread_count) {
	this->thread_count = thread_count;
}

MultiThreadMatrixMultiplication::~MultiThreadMatrixMultiplication() {

}

Matrix* MultiThreadMatrixMultiplication::multiply ( const Matrix& left, const Matrix& right) {
    int rowLeftMatrix, colRightMatrix;

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

    Executor* executor = new Executor(8);
    executor->execute ( left, right, *finalMatrix);

    delete executor;
	return finalMatrix;
}