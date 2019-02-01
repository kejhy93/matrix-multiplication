#include <iostream>
#include <string>

#include "lib/Matrix.h"
#include "lib/MatrixMultiplication.h"
#include "lib/SingleThreadMatrixMultiplication.h"

int main(int argc, char ** argv) {

	std::string path_to_file_left_matrix = "left_matrix";	
	std::string path_to_file_right_matrix = "right_matrix";	

	// Matrix * left_matrix = new Matrix(path_to_file_left_matrix);
	// Matrix * right_matrix = new Matrix(path_to_file_right_matrix);

	Matrix* left_matrix = Matrix::generate_random_matrix(10, 10);
	Matrix* right_matrix = Matrix::generate_random_matrix(10, 10);

	std::cout << "Left matrix" << std::endl;
	Matrix::printMatrix(*left_matrix);

	std::cout << "Right matrix" << std::endl;
	Matrix::printMatrix(*right_matrix);

	bool isSingleThreaded = true;

	MatrixMultiplication * matrix_multiplication = nullptr;

	if ( isSingleThreaded ) {
		matrix_multiplication = new SingleThreadMatrixMultiplication();
	}

	Matrix *final_matrix = matrix_multiplication->multiply(*left_matrix, *right_matrix);

	Matrix::printMatrix(*final_matrix);

	delete final_matrix;
	delete matrix_multiplication;
	delete left_matrix;
	delete right_matrix;
	return 0;
}