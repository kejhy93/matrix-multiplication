#include <iostream>
#include <string>

#include "lib/Matrix.h"
#include "lib/MatrixMultiplication.h"
#include "lib/SingleThreadMatrixMultiplication.h"
#include "lib/MultiThreadMatrixMultiplication.h"

int main(int argc, char ** argv) {

	std::string path_to_file_left_matrix = "left_matrix";	
	std::string path_to_file_right_matrix = "right_matrix";	
  std::string path_to_output_file = "result_matrix";
  
	Matrix * left_matrix = new Matrix(path_to_file_left_matrix);
	Matrix * right_matrix = new Matrix(path_to_file_right_matrix);
  
// 	Matrix* left_matrix = Matrix::generate_random_matrix(10, 10);
// 	Matrix* right_matrix = Matrix::generate_random_matrix(10, 10);

	std::cout << "Left matrix" << std::endl;
	Matrix::printMatrix(*left_matrix);

	std::cout << "Right matrix" << std::endl;
	Matrix::printMatrix(*right_matrix);
  

	bool isSingleThreaded = false;

	MatrixMultiplication * matrix_multiplication = nullptr;

	if ( isSingleThreaded ) {
		std::cout << "using single threaded version of matrix multiplication" << std::endl;
		matrix_multiplication = new SingleThreadMatrixMultiplication();
	} else {
		std::cout << "using multi threaded version of matrix multiplication" << std::endl;
		matrix_multiplication = new MultiThreadMatrixMultiplication();
	}

	Matrix *final_matrix = matrix_multiplication->multiply(*left_matrix, *right_matrix);

	Matrix::printMatrix(*final_matrix);
	final_matrix->export_to_file(path_to_output_file);

	delete final_matrix;
	delete matrix_multiplication;
	delete left_matrix;
	delete right_matrix;
	return 0;
}