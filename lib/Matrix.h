#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <random>

class Matrix {

public:
	Matrix (const std::string & path);
	Matrix ( const int& row, const int& col);
	virtual ~Matrix();

	double get_value( const int & row, const int & col ) const;
	void set_value ( const int & row, const int & col, double n_value );

	int get_col () const;
	int get_row () const;

	static void printMatrix ( const Matrix& matrix);
	static Matrix* generate_random_matrix(const int row, const int col);

	void export_to_file(std::string path) const;

private:
	double** matrix;
	int row;
	int col;

	bool check_parameters ( const int & row, const int & col) const;

	void read_matrix ( std::string path);
	void read_matrix_size(std::ifstream& input_stream);
	void read_matrix_content(std::ifstream& input_stream);

	static double get_random_double();
};

#endif