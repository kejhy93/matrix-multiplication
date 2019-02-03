#include <iostream>
#include <string>
#include <cstring>
#include <chrono>

#include "lib/Matrix.h"
#include "lib/MatrixMultiplication.h"
#include "lib/SingleThreadMatrixMultiplication.h"
#include "lib/MultiThreadMatrixMultiplication.h"


void process_command_line_parameters(const int& argc, char** argv);

int GENERATE_RANDOM_MATRIX = 0;
const std::string random_matrix_param = "-generate-random-matrix";

int MULTI_THREAD = 0;
const std::string multithread = "-multithread";

int main(int argc, char ** argv) {

	process_command_line_parameters(argc, argv);

	std::string path_to_file_left_matrix = "left_matrix";	
	std::string path_to_file_right_matrix = "right_matrix";	
	std::string path_to_output_file = "result_matrix";
  
	Matrix *left_matrix, *right_matrix;

	if ( GENERATE_RANDOM_MATRIX == 0 ) {
		left_matrix = new Matrix(path_to_file_left_matrix);
		right_matrix = new Matrix(path_to_file_right_matrix);
  	} else {
		left_matrix = Matrix::generate_random_matrix(500, 500);
		right_matrix = Matrix::generate_random_matrix(500, 500);

		left_matrix->export_to_file(path_to_file_left_matrix);
		right_matrix->export_to_file(path_to_file_right_matrix);
	}

	// std::cout << "Left matrix" << std::endl;
	// Matrix::printMatrix(*left_matrix);

	// std::cout << "Right matrix" << std::endl;
	// Matrix::printMatrix(*right_matrix);
  
	MatrixMultiplication * matrix_multiplication = nullptr;

	if ( MULTI_THREAD == 0 ) {
		std::cout << "using single threaded version of matrix multiplication" << std::endl;
		matrix_multiplication = new SingleThreadMatrixMultiplication();
	} else {
		std::cout << "using multi threaded version of matrix multiplication" << std::endl;
		matrix_multiplication = new MultiThreadMatrixMultiplication();
	}

	auto start = std::chrono::high_resolution_clock::now();

	Matrix *final_matrix = matrix_multiplication->multiply(*left_matrix, *right_matrix);

	// Matrix::printMatrix(*final_matrix);
	final_matrix->export_to_file(path_to_output_file);


	delete final_matrix;
	delete matrix_multiplication;
	delete left_matrix;
	delete right_matrix;

	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "Execution time=" << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << " ms" << std::endl;
	return 0;
}


void process_command_line_parameters(const int& argc, char** argv) {
	for ( int a = 0 ; a < argc ; ++ a ) {
		if ( strcmp(argv[a], random_matrix_param.c_str()) == 0 ) {
			GENERATE_RANDOM_MATRIX = 1;
		}
		if ( strcmp(argv[a], multithread.c_str()) == 0 ) {
			MULTI_THREAD = 1;
		}
	}
}