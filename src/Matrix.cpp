#include "Matrix.h"

Matrix::Matrix(const std::string & path) {
	this->row = 0;
	this->col = 0;
	this->matrix = nullptr;
	
	read_matrix(path);
}

Matrix::Matrix(const int& row, const int& col) {
	this->row = row;
	this->col = col;

	this->matrix = new double*[row];
	for ( int rowCounter = 0 ; rowCounter < row ; ++ rowCounter ) {
		this->matrix[rowCounter] = new double[col];
		for ( int colCounter = 0 ; colCounter < col ; ++ colCounter ) {
			this->matrix[rowCounter][colCounter] = 0;
		}
	}
}

Matrix::~Matrix() {
	for ( int rowCounter = 0 ; rowCounter < this->row ; ++ rowCounter ) {
		delete[] this->matrix[rowCounter];
	}
	delete[] this->matrix;
}

double Matrix::get_value(const int & row, const int & col) const {
	return matrix[row][col];
}

void Matrix::set_value ( const int & row, const int & col, double n_value ) {
	bool are_parameters_valid = this->check_parameters(row, col);

	if ( !are_parameters_valid ) {
		std::cerr << "Parameters are wrong" << std::endl;
		return;
	}

	this->matrix[row][col] = n_value;
}

int Matrix::get_col () const {
	return this->col;
}

int Matrix::get_row () const {
	return this->row;
}

void Matrix::printMatrix(const Matrix& matrix) {
	for ( int rowCounter = 0 ; rowCounter < matrix.get_row() ; ++ rowCounter) {
		for ( int colCounter = 0 ; colCounter < matrix.get_col() ; ++ colCounter ) {
			std::cout << matrix.get_value(rowCounter, colCounter) << " ";
		}
		std::cout << std::endl;
	}
}


Matrix* Matrix::generate_random_matrix(const int row, const int col) {
	Matrix* random_matrix = new Matrix(row, col);

	for ( int row_counter = 0 ; row_counter < row ; ++ row_counter) {
		for ( int col_counter = 0 ; col_counter < col ; ++ col_counter ) {
			random_matrix->set_value(row_counter, col_counter, row_counter*row + col_counter);
		}
	}

	return random_matrix;
}

void Matrix::export_to_file ( std::string path) const {
	std::cout << "export of matrix started" << std::endl;
	std::ofstream out_stream(path.c_str(), std::ios::out);

	out_stream << row << " " << col << "\n";
	for ( int row_counter = 0 ; row_counter < row ; ++ row_counter) {
		for ( int col_counter = 0 ; col_counter < col-1 ; ++ col_counter ) {
			out_stream << matrix[row_counter][col_counter] << " ";
		}
		out_stream << matrix[row_counter][col-1] << "\n";
	}

	std::cout << "export of matrix is finished" << std::endl;
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
}

bool Matrix::check_parameters ( const int & row, const int & col) const {
	bool is_row_valid = 0 <= row && row < this->row;
	bool is_col_valid = 0 <= col && col < this->col;

	return is_row_valid && is_col_valid;
}