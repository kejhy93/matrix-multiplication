#ifndef __SINGLE_THREAD_MATRIX_MULTIPLICATION_H__
#define __SINGLE_THREAD_MATRIX_MULTIPLICATION_H__

#include "MatrixMultiplication.h"

class SingleThreadMatrixMultiplication : public MatrixMultiplication {
public:
	Matrix* multiply ( const Matrix& left, const Matrix& right);
};

#endif