#include <iostream>
#include "lib/Matrix.h"
#include "Matrix.h"

const int SUCCESS_TEST = 0;
const int FAILED_TEST = 1;

int test_matrixConstructor();

int main()
{
    std::cout << "TestMatrix" << std::endl;
    int result = test_matrixConstructor();
    if (result == FAILED_TEST)
        return FAILED_TEST;

    return SUCCESS_TEST;
}

int test_matrixConstructor()
{
    int WIDTH = 2000;
    int HEIGHT = 3000;

    Matrix *matrix = new Matrix(HEIGHT, WIDTH);

    int width = matrix->get_col();
    if (WIDTH != width)
    {
        std::cout << "Width is not correct. Expected " << WIDTH << ", got " << width << std::endl;
        delete matrix;
        return FAILED_TEST;
    }
    std::cout << "Width is " << width << std::endl;

    int height = matrix->get_row();
    if (HEIGHT != height)
    {
        std::cout << "Height is not correct. Expected " << HEIGHT << ", got " << height << std::endl;
        delete matrix;
        return FAILED_TEST;
    }
    std::cout << "Height is " << height << std::endl;

    delete matrix;
    return SUCCESS_TEST;
}