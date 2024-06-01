#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Matrix.h"

int main()
{
    Matrix matrix1("Matrix1.txt");
    Matrix matrix2("Matrix2.txt");
    Matrix matrix3 = std::move(matrix1 * matrix2);
    matrix3.write_to_file("ResultedMatrix.txt");
    return 0;
}