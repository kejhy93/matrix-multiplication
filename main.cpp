#include <iostream>
#include <string>

#include "lib/Matrix.h"

int main(int argc, char ** argv) {

	std::string path_to_file = "A";	

	Matrix * matrix = new Matrix(path_to_file);

	delete matrix;
	return 0;
}