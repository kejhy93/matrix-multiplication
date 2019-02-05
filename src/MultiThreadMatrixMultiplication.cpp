#include "MultiThreadMatrixMultiplication.h"

MultiThreadMatrixMultiplication::MultiThreadMatrixMultiplication( const int thread_count) {
	this->thread_count = thread_count;
}

MultiThreadMatrixMultiplication::~MultiThreadMatrixMultiplication() {

}

Matrix* MultiThreadMatrixMultiplication::multiply ( const Matrix& left, const Matrix& right) {
    int rowLeftMatrix, colRightMatrix;

    // size of result matrix
	rowLeftMatrix = left.get_row();
	colRightMatrix = right.get_col();

	// check if given matrices can be multiplied
	bool areMatrixCompatibleForMultiplication = MatrixMultiplication::areMatricesCompatibleForMultiplication(left, right);

	if ( !areMatrixCompatibleForMultiplication ) {
		std::cerr << "Given matrices are not compatible to multiple." << std::endl;
		return new Matrix(0,0);
	}

	int rowMultipliedMatrix = rowLeftMatrix;
	int colMultipliedMatrix = colRightMatrix;

	// create result matrix
	Matrix* finalMatrix = new Matrix(rowMultipliedMatrix, colMultipliedMatrix);

	// create executor and execute executor to solve problem
    Executor* executor = new Executor(8);
    executor->execute ( left, right, *finalMatrix);

    delete executor;
	return finalMatrix;
}