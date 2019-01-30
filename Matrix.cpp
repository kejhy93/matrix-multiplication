#include "Matrix.h"

Matrix::Matrix(const std::string & path) {
	this->row = 0;
	this->col = 0;
	this->matrix = nullptr;

	std::cout << "[Matrix::Matrix] Path to file \"" << path << "\"" << std::endl;
	
	read_matrix(path);
}

Matrix::~Matrix() {
	std::cout << "[Matrix::~Matrix] destruction" << std::endl;
}

double Matrix::get_value(const int & row, const int & col) const {
	return matrix[row][col];
}

void Matrix::set_value ( const int & row, const int & col, const double & n_value ) {
	bool are_parameters_valid = this->check_parameters(row, col);

	if ( !are_parameters_valid ) {
		std::cerr << "Parameters are wrong" << std::endl;
		return;
	}

	this->matrix[row][col] = n_value;
}

void Matrix::read_matrix ( std::string path) {
	read_matrix_size ( path );
	read_matrix_content ( path );
}

void Matrix::read_matrix_size(std::string path) {
	
}

void Matrix::read_matrix_content(std::string path) {

}

bool Matrix::check_parameters ( const int & row, const int & col) const {
	bool is_row_valid = 0 >= row && row > this->row;
	bool is_col_valid = 0 >= col && col > this->col;

	return is_row_valid && is_col_valid;
}