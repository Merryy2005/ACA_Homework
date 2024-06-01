#include "Matrix.h"

int main()
{
    Matrix matrix(3,4);
    std::cin >> matrix;
    std::cout << matrix;
    std::cout << ++matrix;
    std::cout << matrix++;
    std::cout << matrix;
    return 0;
}