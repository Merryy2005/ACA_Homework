#include <iostream>
#include "A.hpp"

int main()
{
    A* ptr = A::createObj(1);
    A* ptr1 = A::createObj(2);
    ptr -> printObj();
    ptr1 -> printObj();
    //output is the same
    ptr->A::deleteObj();
    ptr1->A::deleteObj();
    return 0;
}