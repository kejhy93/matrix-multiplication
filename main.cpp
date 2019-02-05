#include <iostream>
#include <string>
#include <cstring>
#include <chrono>

#include "lib/Matrix.h"
#include "lib/MatrixMultiplication.h"
#include "lib/SingleThreadMatrixMultiplication.h"
#include "lib/MultiThreadMatrixMultiplication.h"
#include "lib/ArgumentResolver.h"

int main(int argc, char ** argv) {

	// Parse command line arguments
	ArgumentResolver *command_line_resolver = new ArgumentResolver(argc, argv);
	if ( command_line_resolver->parse_command_line_arguments() != 0 ) {
		std::cerr << "Command line arguments are wrong" << std::endl;
		delete command_line_resolver;
		return 1;
	}
  
	Matrix *left_matrix, *right_matrix;

	if ( command_line_resolver->shouldIGenerateRandomMatrices() ) {
		left_matrix = Matrix::generate_random_matrix(command_line_resolver->get_left_matrix_row(), command_line_resolver->get_left_matrix_col());
		right_matrix = Matrix::generate_random_matrix(command_line_resolver->get_right_matrix_row(), command_line_resolver->get_right_matrix_col());

		left_matrix->export_to_file(command_line_resolver->get_path_to_left_matrix());
		right_matrix->export_to_file(command_line_resolver->get_path_to_right_matrix());
	} else {
		left_matrix = new Matrix(command_line_resolver->get_path_to_left_matrix());
		right_matrix = new Matrix(command_line_resolver->get_path_to_right_matrix());
  	} 
  
	MatrixMultiplication * matrix_multiplication = nullptr;

	if ( command_line_resolver->shouldIRunMultiThread() ) {
		std::cout << "using multi threaded version of matrix multiplication, use " << command_line_resolver->how_many_threads() << " threads."  << std::endl;
		matrix_multiplication = new MultiThreadMatrixMultiplication( command_line_resolver->how_many_threads() );
	} else {
		std::cout << "using single threaded version of matrix multiplication" << std::endl;
		matrix_multiplication = new SingleThreadMatrixMultiplication();
	}

	auto start = std::chrono::high_resolution_clock::now();

	Matrix *final_matrix = matrix_multiplication->multiply(*left_matrix, *right_matrix);

	if ( final_matrix->get_row() == 0 && final_matrix->get_col() == 0 ) {
		delete left_matrix;
		delete right_matrix;
		delete final_matrix;
		delete command_line_resolver;
		delete matrix_multiplication;

		return 1;
	}

	if ( command_line_resolver->shouldIExportResultMatrix()) {
		final_matrix->export_to_file(command_line_resolver->get_path_to_result_matrix());
	} else {
		Matrix::printMatrix(*final_matrix);
	}

	delete command_line_resolver;
	delete final_matrix;
	delete matrix_multiplication;
	delete left_matrix;
	delete right_matrix;

	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "Execution time=" << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << " ms" << std::endl;
	return 0;
}