#ifndef __MULTI_THREAD_MATRIX_MULTIPLICATION_H__
#define __MULTI_THREAD_MATRIX_MULTIPLICATION_H__

#include "MatrixMultiplication.h"
#include "MatrixThreadData.h"
#include "Executor.h"
#include <thread>
#include <iostream>

class MultiThreadMatrixMultiplication : public MatrixMultiplication {
public:
	MultiThreadMatrixMultiplication(const int thread_count);
	virtual ~MultiThreadMatrixMultiplication();
	
	Matrix* multiply ( const Matrix& left, const Matrix& right);

protected:
	int thread_count;
};

#endif