#include <iostream>
#include "A.h"

int main()
{
    A obj(12);
    std::cout << obj++ << std::endl; //12 (postfix)
    std::cout << obj << std::endl; // 13
    std::cout << ++obj << std::endl; //14 (prefix)
    return 0;
}