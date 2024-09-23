#include <iostream>

#include "lib/MatrixMultiplication.h"
#include "lib/Matrix.h"

const int SUCCESS_TEST = 0;
const int FAILED_TEST = 1;

int test_matricesCompatibleForMultiplication();
int test_linearCombination();

int main()
{

    int result = test_matricesCompatibleForMultiplication();
    if (result == FAILED_TEST)
    {
        std::cout << "Failed test for matrix compatibility" << std::endl;
        return FAILED_TEST;
    }

    result = test_linearCombination();
    if (result == FAILED_TEST)
    {
        std::cout << "Failed test for linear combination" << std::endl;
        return FAILED_TEST;
    }

    return SUCCESS_TEST;
}

int test_matricesCompatibleForMultiplication()
{
    Matrix *leftMatrix = new Matrix(2, 3);
    Matrix *rightMatrix = new Matrix(3, 2);

    bool areMatricesCompatible = MatrixMultiplication::areMatricesCompatibleForMultiplication(*leftMatrix, *rightMatrix);
    if (areMatricesCompatible == false)
    {
        std::cout << "Compatible matrices to multiple FAILED" << std::endl;
        delete leftMatrix;
        delete rightMatrix;
        return FAILED_TEST;
    }
    std::cout << "Compatible matrices check PASSED" << std::endl;

    areMatricesCompatible = MatrixMultiplication::areMatricesCompatibleForMultiplication(*rightMatrix, *leftMatrix);
    if (areMatricesCompatible == false)
    {
        std::cout << "Compatible matrices to multiple FAILED" << std::endl;
        delete leftMatrix;
        delete rightMatrix;
        return FAILED_TEST;
    }
    std::cout << "Compatible matrices check PASSED" << std::endl;

    delete leftMatrix;
    delete rightMatrix;

    leftMatrix = new Matrix(3, 3);
    rightMatrix = new Matrix(3, 3);

    areMatricesCompatible = MatrixMultiplication::areMatricesCompatibleForMultiplication(*leftMatrix, *rightMatrix);
    if (areMatricesCompatible == false)
    {
        std::cout << "Compatible matrices to multiple FAILED" << std::endl;
        delete leftMatrix;
        delete rightMatrix;
        return FAILED_TEST;
    }
    std::cout << "Compatible matrices check PASSED" << std::endl;

    areMatricesCompatible = MatrixMultiplication::areMatricesCompatibleForMultiplication(*rightMatrix, *leftMatrix);
    if (areMatricesCompatible == false)
    {
        std::cout << "Compatible matrices to multiple FAILED" << std::endl;
        delete leftMatrix;
        delete rightMatrix;
        return FAILED_TEST;
    }
    std::cout << "Compatible matrices check PASSED" << std::endl;

    delete leftMatrix;
    delete rightMatrix;

    leftMatrix = new Matrix(3, 4);
    rightMatrix = new Matrix(3, 4);

    areMatricesCompatible = MatrixMultiplication::areMatricesCompatibleForMultiplication(*leftMatrix, *rightMatrix);
    if (areMatricesCompatible == true)
    {
        std::cout << "Incompatible matrices to multiple FAILED" << std::endl;
        delete leftMatrix;
        delete rightMatrix;
        return FAILED_TEST;
    }
    std::cout << "Incompatible matrices check PASSED" << std::endl;

    areMatricesCompatible = MatrixMultiplication::areMatricesCompatibleForMultiplication(*rightMatrix, *leftMatrix);
    if (areMatricesCompatible == true)
    {
        std::cout << "Incompatible matrices to multiple FAILED" << std::endl;
        delete leftMatrix;
        delete rightMatrix;
        return FAILED_TEST;
    }
    std::cout << "Incompatible matrices check PASSED" << std::endl;

    delete leftMatrix;
    delete rightMatrix;

    return SUCCESS_TEST;
}

int test_linearCombination()
{
    Matrix *leftMatrix = new Matrix(2, 2);
    Matrix *rightMatrix = new Matrix(2, 2);

    //  (   0   1   )
    //  (   2   3   )
    leftMatrix->set_value(0, 0, 0.0);
    leftMatrix->set_value(0, 1, 1.0);
    leftMatrix->set_value(1, 0, 2.0);
    leftMatrix->set_value(1, 1, 3.0);

    //  (   4   5   )
    //  (   6   7   )
    rightMatrix->set_value(0, 0, 4.0);
    rightMatrix->set_value(0, 1, 5.0);
    rightMatrix->set_value(1, 0, 6.0);
    rightMatrix->set_value(1, 1, 7.0);

    double result = MatrixMultiplication::linear_combination(*leftMatrix, *rightMatrix, 0, 0);
    //  (   0   1   )   *   (   4   )
    //                      (   6   )
    if (result != 6.0)
    {
        std::cout << "Failed linear combination first row, first col" << std::endl;
        std::cout << "Expected 6.0, got " << result << std::endl;
        delete leftMatrix;
        delete rightMatrix;
        return FAILED_TEST;
    }

    result = MatrixMultiplication::linear_combination(*leftMatrix, *rightMatrix, 0, 1);
    //  (   0   1   )   *   (   5   )
    //                      (   7   )
    if (result != 7.0)
    {
        std::cout << "Failed linear combination first row, second col" << std::endl;
        std::cout << "Expected 7.0, got " << result << std::endl;
        delete leftMatrix;
        delete rightMatrix;
        return FAILED_TEST;
    }

    result = MatrixMultiplication::linear_combination(*leftMatrix, *rightMatrix, 1, 0);
    //  (   2   3   )   *   (   4   )
    //                      (   6   )
    if (result != 26.0)
    {
        std::cout << "Failed linear combination second row, first col" << std::endl;
        std::cout << "Expected 26.0, got " << result << std::endl;
        delete leftMatrix;
        delete rightMatrix;
        return FAILED_TEST;
    }

    result = MatrixMultiplication::linear_combination(*leftMatrix, *rightMatrix, 1, 1);
    //  (   2   3   )   *   (   5   )
    //                      (   7   )
    if (result != 31.0)
    {
        std::cout << "Failed linear combination second row, second col" << std::endl;
        std::cout << "Expected 31.0, got " << result << std::endl;
        delete leftMatrix;
        delete rightMatrix;
        return FAILED_TEST;
    }

    delete leftMatrix;
    delete rightMatrix;
    return SUCCESS_TEST;
}