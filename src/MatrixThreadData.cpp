#include "MatrixThreadData.h"

MatrixThreadData::MatrixThreadData( const Matrix& left, const Matrix& right, Matrix& final_matrix, const int& row, const int& col) 
    : left_matrix(left), right_matrix(right), final_matrix(final_matrix), row(row), col(col) {}

MatrixThreadData::~MatrixThreadData() {}