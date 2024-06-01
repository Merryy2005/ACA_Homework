#include <cstdlib>
#include <ctime>
#include "Matrix.h"

int main()
{
    srand(time(0));
    Matrix matrix(3,4);
    Matrix matrix1(3,4);
    std::cout << matrix << matrix1 << std::endl;
    Matrix matrix2(matrix + matrix1);
    std::cout << matrix2;
    Matrix matrix3;
    matrix3 = matrix + matrix1;
    return 0;
}