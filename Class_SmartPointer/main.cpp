#include <iostream>
#include "SmartPtr.hpp"
#include "A.hpp"

int main()
{
    try
    {
        SmartPtr<A> p = new A(5);
        std::cout << *p << std::endl;
        p->display();
        throw std::string("Excpetion");
    }
    catch(const std::string& s)
    {
        std::cout << s << std::endl;
    }
    return 0;
}