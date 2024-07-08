#include "Matrix.hpp"

int main()
{
    Matrix<int> m(4,5);
    std::cout << m;
    try{
        std::cout << m.at(3,2);
        std::cout << m.at(4,2);
    }
    catch(std::exception& e)
    {
        std::cout << e.what();
    }
    return 0;
}