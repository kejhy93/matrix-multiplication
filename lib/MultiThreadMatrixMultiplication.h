#ifndef __MULTI_THREAD_MATRIX_MULTIPLICATION_H__
#define __MULTI_THREAD_MATRIX_MULTIPLICATION_H__

#include "MatrixMultiplication.h"
#include "MatrixThreadData.h"
#include "Executor.h"
// #include <pthread.h>
#include <thread>
#include <iostream>

class MultiThreadMatrixMultiplication : public MatrixMultiplication {
public:
	virtual ~MultiThreadMatrixMultiplication();
	Matrix* multiply ( const Matrix& left, const Matrix& right);

	double partiallyMatrixMultiplication ( const Matrix& left, const Matrix& right, const int& row, const int& col);

};

#endif