#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Matrix.h"

int main()
{
    Matrix<double> matrix1("Matrix1.txt");
    Matrix<double> matrix2("Matrix2.txt");
    Matrix<double> matrix3 = matrix1 * matrix2;
    matrix3.write_to_file("ResultedMatrix.txt");
    return 0;
}