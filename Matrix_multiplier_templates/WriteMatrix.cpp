#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Matrix.h"

int main()
{
    srand(time(0));
    Matrix<double> matrix1(3,4);
    Matrix<double> matrix2(4,5);
    matrix1.write_to_file("Matrix1.txt");
    matrix2.write_to_file("Matrix2.txt");
    return 0;
}