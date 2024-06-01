#include "A.hpp"

A* A::s_ptr = nullptr;

A::A(int x) : m_x(x)
{

}

A* A::createObj(int x)
{
    if(A::s_ptr == nullptr)
    {
        A::s_ptr = new A(x);
    }
    return A::s_ptr;
}

void A::printObj()
{
    std::cout << "X = " << m_x << std::endl;
    std::cout << "Adress = " << this << std::endl;
}

void A::deleteObj()
{
    delete A::s_ptr;
    A::s_ptr = nullptr;
}

A::~A()
{

}