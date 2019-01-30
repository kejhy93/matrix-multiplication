#include <iostream>
#include <string>

#include "Matrix.h"

int main(int argc, char ** argv) {

	std::string path_to_file = "a";	

	Matrix * matrix = new Matrix(path_to_file);

	delete matrix;
	return 0;
}