#include "Matrix.h"

Matrix::Matrix() : m_ptr(nullptr) , m_row(0) , m_col(0)
{

}

Matrix::Matrix(int row , int col) : m_ptr(new int*[row]) , m_row(row) , m_col(col) 
{
    for(int i = 0 ; i < m_row ; i++){
        m_ptr[i] = new int[m_col];
    }
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            m_ptr[i][j] = 0;
        }
    }

}

Matrix::Matrix(const Matrix& other) : m_ptr(new int*[other.m_row]) , m_row(other.m_row) , m_col(other.m_col)
{
    for(int i = 0 ; i < m_row ; i++){
        m_ptr[i] = new int[m_col];
    }
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            m_ptr[i][j] = other.m_ptr[i][j];
        }
    }
}

Matrix& Matrix::operator= (const Matrix& other)
{
    if(this != &other)
    {
        for(int i = 0 ; i < m_row ; i++)
        {
            delete[] m_ptr[i];
            m_ptr[i] = nullptr;
        }
        delete[] m_ptr;
        m_ptr = nullptr;
        m_row = other.m_row;
        m_col = other.m_col;
        m_ptr = new int*[m_row];
        for(int i = 0 ; i < m_row ; i++){
            m_ptr[i] = new int[m_col];
        }
        for(int i = 0 ; i < m_row ; i++)
        {
            for(int j = 0 ; j < m_col ; j++)
            {
                m_ptr[i][j] = other.m_ptr[i][j];
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator++()
{
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            m_ptr[i][j]+=3;
        }
    }
    return *this;
}

Matrix Matrix::operator++(int)
{
    Matrix temp(*this);
    ++(*this);
    return temp;
}
std::ostream& operator<< (std::ostream& os, const Matrix& mtrx)
{
    os << "Matrix  : " << mtrx.m_row << "x" << mtrx.m_col << std::endl;
    for(int i = 0 ; i < mtrx.m_row ; i++)
    {
        for(int j = 0 ; j < mtrx.m_col ; j++)
        {
            os << mtrx.m_ptr[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator>> (std::istream& is, Matrix& mtrx)
{
    std::cout << "Input elements : ";
    for(int i = 0 ; i < mtrx.m_row ; i++)
    {
        for(int j = 0 ; j < mtrx.m_col ; j++)
        {
            is >> mtrx.m_ptr[i][j];
        }
    }
    return is;
}


Matrix::~Matrix()
{
    for(int i = 0 ; i < m_row ; i++)
    {
        delete[] m_ptr[i];
        m_ptr[i] = nullptr;
    }
    delete[] m_ptr;
    m_ptr = nullptr;
}