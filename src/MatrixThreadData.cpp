#include "MatrixThreadData.h"

MatrixThreadData::MatrixThreadData( const Matrix& left, const Matrix& right, Matrix& final_matrix, const int row, const int col, const int id) 
    : m_left_matrix(left), m_right_matrix(right), m_final_matrix(final_matrix), m_row(row), m_col(col), m_id(id) {}

MatrixThreadData::~MatrixThreadData() {}