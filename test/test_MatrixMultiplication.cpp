#include <iostream>

#include "lib/MatrixMultiplication.h"
#include "lib/Matrix.h"

const int SUCCESS_TEST = 0;
const int FAILED_TEST = 1;

int test_matricesCompatibleForMultiplication();
int test_linearCombination();

int main() {

    int result = test_matricesCompatibleForMultiplication();
    if (result == FAILED_TEST)
        return FAILED_TEST;
    
    result = test_linearCombination();
    if (result == FAILED_TEST)
        return FAILED_TEST;

    return SUCCESS_TEST;
}

int test_matricesCompatibleForMultiplication() {
    Matrix* leftMatrix = new Matrix(2, 3);
    Matrix* rightMatrix = new Matrix(3 ,2);

    bool areMatricesCompatible = MatrixMultiplication::areMatricesCompatibleForMultiplication(*leftMatrix, *rightMatrix);
    if (areMatricesCompatible == false) {
        std::cout << "Compatible matrices to multiple" << std::endl;
        return FAILED_TEST; 
    }
    std::cout << "Compatible matrices check PASSED" << std::endl;

    areMatricesCompatible = MatrixMultiplication::areMatricesCompatibleForMultiplication(*rightMatrix,*leftMatrix);
    if (areMatricesCompatible == true) {
        std::cout << "Incompatible matrices to multiple" << std::endl;
        return FAILED_TEST;
    }
    std::cout << "Incompatible matrices check PASSED" << std::endl;
    
    delete leftMatrix;
    delete rightMatrix;

    leftMatrix = new Matrix(3, 3);
    rightMatrix = new Matrix(3, 3);

    areMatricesCompatible = MatrixMultiplication::areMatricesCompatibleForMultiplication(*rightMatrix,*leftMatrix);
    if (areMatricesCompatible == true) {
        std::cout << "Compatible matrices to multiple" << std::endl;
        return FAILED_TEST;
    }
    std::cout << "Compatible matrices check PASSED" << std::endl;

    areMatricesCompatible = MatrixMultiplication::areMatricesCompatibleForMultiplication(*rightMatrix,*leftMatrix);
    if (areMatricesCompatible == true) {
        std::cout << "Compatible matrices to multiple" << std::endl;
        return FAILED_TEST;
    }
    std::cout << "Compatible matrices check PASSED" << std::endl;

    return SUCCESS_TEST;
}

int test_linearCombination() {
    
}