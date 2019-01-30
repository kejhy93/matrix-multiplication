#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <string>

class Matrix {

public:
	Matrix (const std::string & path);
	virtual ~Matrix();

	double get_value( const int & row, const int & col ) const;
	void set_value ( const int & row, const int & col, const double & n_value );

private:
	double** matrix;
	int row;
	int col;

	bool check_parameters ( const int & row, const int & col) const;

	void read_matrix ( std::string path);
	void read_matrix_size(std::string path);
	void read_matrix_content(std::string path);
};

#endif