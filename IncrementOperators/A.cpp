#include "A.h"

A::A() : m_cnt(0)
{

}

A::A(int cnt) : m_cnt(cnt)
{

}

A::A(const A& other) : m_cnt(other.m_cnt) 
{

}

A& A::operator++()
{
    ++m_cnt;
    return *this;
}

A A::operator++(int)
{
    A temp(*this);
    ++(*this);
    return temp; 
}

std::ostream& operator<< (std::ostream& os, const A& obj)
{
    os << obj.m_cnt;
    return os;
}

A::~A()
{

}