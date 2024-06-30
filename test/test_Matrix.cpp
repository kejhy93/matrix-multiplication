#include <iostream>
#include "lib/Matrix.h"
#include "Matrix.h"

const int FAILED_TEST = 0;
const int SUCCESS_TEST = 1;

int main() {

    int WIDTH = 2;
    int HEIGHT = 3;

    Matrix* matrix = new Matrix(WIDTH, HEIGHT);

    int width = matrix->get_col();
    if ( WIDTH != width) {
        std::cout << "Width is not correct. Expected " << WIDTH << ", got " << width << std::endl;
        return FAILED_TEST;
    }

    int height = matrix->get_row();
    if ( HEIGHT != height) {
        std::cout << "Height is not correct. Expected " << HEIGHT << ", got " << height << std::endl;
        return FAILED_TEST;
    }

    delete matrix;
    return SUCCESS_TEST;
}