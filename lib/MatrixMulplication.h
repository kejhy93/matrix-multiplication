#ifndef __MATRIX_MULTIPLICATION_H__
#define __MATRIX_MULTIPLICATION_H__

class MatrixMultiplication {

public:
	virtual Matrix* multiply(const Matrix& left, const Matrix& right) = 0;
};

#endif