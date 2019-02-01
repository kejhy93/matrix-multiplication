#ifndef __MATRIX_THREAD_DATA_H__
#define __MATRIX_THREAD_DATA_H__

#include "Matrix.h"

class MatrixThreadData {
public:
    MatrixThreadData();
    MatrixThreadData(const Matrix& left, const Matrix& right, Matrix& final, const int row, const int col, const int id);
	virtual ~MatrixThreadData();

    const Matrix& m_left_matrix;
    const Matrix& m_right_matrix;
    Matrix& m_final_matrix;

    const int m_row;
    const int m_col;

    const int m_id;
};

#endif