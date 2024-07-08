#include "Matrix.hpp"

int main()
{
    Matrix<int> m(4,5);
    std::cout << m;
    std::cout << m.at(3,2);
    std::cout << m.at(4,2);
}