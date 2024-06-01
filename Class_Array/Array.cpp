#include "Array.h"

Array::Array() : m_arr(nullptr) , m_size(0)
{

}

Array::Array(int size) : m_size(size)
{
    m_arr = new int[m_size];
    for(int i = 0 ; i < m_size ; i++)
    {
        m_arr[i] = i;
    }
}

Array::Array(Array& other) : m_size(other.m_size)
{
    m_arr = new int[m_size];
    for(int i = 0 ; i < m_size ; i++)
    {
        m_arr[i] = other.m_arr[i];
    }
}

int Array::getSize() const
{
    return m_size;
}

int& Array::operator[] (int index)
{
    return m_arr[index];
}

int Array::operator[](int index) const
{
    return m_arr[index];
}

std::ostream& operator<< (std::ostream& os, const Array& arr)
{
    os << "Size : " << arr.m_size << std::endl;
    for(int i = 0 ; i < arr.m_size ; i++)
    {
        os << arr[i] << " ";
    }
    os << std::endl;
    return os;
}

Array::~Array()
{
    delete[] m_arr;
    m_arr = nullptr;
    m_size = 0;
}