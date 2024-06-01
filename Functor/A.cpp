#include "A.h"

void A::operator() () const
{
    std::cout << "No parameters" << std::endl;
}
        
int A::operator() (int x) const
{
    std::cout << "One parameter" << std::endl;
    return x+1;
}

int A::operator() (int x , int y) const
{
    std::cout << "Two parameters" << std::endl;
    return x+y+2;
}