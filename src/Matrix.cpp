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
	for ( int rowCounter = 0 ; rowCounter < this->row ; ++ rowCounter ) {
		delete[] this->matrix[rowCounter];
	}
	delete[] this->matrix;
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
	// Verify existance of file
	std::ifstream in_stream ( path.c_str(), std::ios::in );

	read_matrix_size ( in_stream );
	read_matrix_content ( in_stream );
}

void Matrix::read_matrix_size(std::ifstream& input_stream) {
	std::string line;
	getline(input_stream, line);
	std::stringstream ss ( line );
	ss >> this->row >> this->col;
	std::cout << "Size of matrix " << this->row << "x" << this->col << std::endl;

	this->matrix = new double*[this->row];
	for ( int rowCounter = 0 ; rowCounter < this->row ; ++ rowCounter ) {
		this->matrix[rowCounter] = new double[this->col];
	}
}

void Matrix::read_matrix_content(std::ifstream & input_stream) {
	double value = 0.0;
	std::string line;

	for ( int row = 0 ; row < this->row ; ++ row ) {
		getline(input_stream, line);
		std::stringstream ss ( line );
		for ( int col = 0 ; col < this->col ; ++ col ) {
			ss >> value;
			this->matrix[row][col] = value;
		}
	}

	for ( int row = 0 ; row < this->row ; ++ row ) {
		for ( int col = 0 ; col < this->col ; ++ col ) {
			std::cout << this->matrix[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

bool Matrix::check_parameters ( const int & row, const int & col) const {
	bool is_row_valid = 0 >= row && row > this->row;
	bool is_col_valid = 0 >= col && col > this->col;

	return is_row_valid && is_col_valid;
}