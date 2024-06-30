#include "Matrix.h"

const int FAILED_TEST = 1;
const int SUCCESS_TEST = 0;

int main() {

    auto WIDTH = 2;
    auto HEIGHT = 3;

    auto matrix = new Matrix(WIDTH, HEIGHT);

    auto width = matrix->get_col();
    if ( WIDTH != width) {
        std::cout << "Width is not correct. Expected " << WIDTH << ", got " << width << std::endl;
        return FAILED_TEST;
    }

    auto height = matrix->get_row();
    if ( HEIGHT != height) {
        std::cout << "Height is not correct. Expected " << HEIGHT << ", got " << height << std::endl;
        return FAILED_TEST;
    }

    return SUCCESS_TEST;
}