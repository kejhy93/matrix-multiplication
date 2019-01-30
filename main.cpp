#include <iostream>
#include <string>

#include "lib/Matrix.h"
#include "lib/MatrixMultiplication.h"
#include "lib/SingleThreadMatrixMultiplication.h"

int main(int argc, char ** argv) {

	std::string path_to_file_left_matrix = "left_matrix";	
	std::string path_to_file_right_matrix = "right_matrix";	

	Matrix * left_matrix = new Matrix(path_to_file_left_matrix);
	Matrix * right_matrix = new Matrix(path_to_file_right_matrix);

	MatrixMultiplication * singleThreadMultiplication = new SingleThreadMatrixMultiplication();

	Matrix *finalMatrix = singleThreadMultiplication->multiply(*left_matrix, *right_matrix);

	for ( int rowCounter = 0 ; rowCounter < finalMatrix->get_row() ; ++ rowCounter) {
		for ( int colCounter = 0 ; colCounter < finalMatrix->get_col() ; ++ colCounter ) {
			std::cout << finalMatrix->get_value(rowCounter, colCounter) << " ";
		}
		std::cout << std::endl;
	}

	if ( finalMatrix != nullptr)
		delete finalMatrix;

	delete singleThreadMultiplication;
	delete left_matrix;
	delete right_matrix;
	return 0;
}