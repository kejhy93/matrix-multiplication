#ifndef __MATRIX_THREAD_DATA_H__
#define __MATRIX_THREAD_DATA_H__

#include "Matrix.h"

class MatrixThreadData {
public:
    MatrixThreadData();
    MatrixThreadData(const Matrix& left, const Matrix& right, Matrix& final, const int &row, const int& col);
	virtual ~MatrixThreadData();

    const Matrix& left_matrix;
    const Matrix& right_matrix;
    Matrix& final_matrix;

    const int& row;
    const int& col;
};

#endif