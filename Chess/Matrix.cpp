#include "Matrix.h"

Matrix::Matrix() : m_row(0) , m_col(0) , m_ptr(nullptr)
{

}

Matrix::Matrix(int row , int col) : m_row(row) , m_col(col) , m_ptr(new Color*[row])
{
    for(int i = 0 ; i < m_row ; i++){
        m_ptr[i] = new Color[m_col];
    }
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            m_ptr[i][j] = Color::black;
        }
    }

}

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this != &other)
    {
        for (int i = 0; i < m_row; ++i)
        {
            delete[] m_ptr[i];
        }
        delete[] m_ptr;
        m_row = other.m_row;
        m_col = other.m_col;
        m_ptr = new Color*[m_row];
        for (int i = 0; i < m_row; ++i)
        {
            m_ptr[i] = new Color[m_col];
            for (int j = 0; j < m_col; ++j)
            {
                m_ptr[i][j] = other.m_ptr[i][j];
            }
        }
    }
    return *this;
}

void Matrix::printMatrix()
{
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            std::cout << (int)m_ptr[i][j] <<" ";
        }
        std::cout << std::endl;
    }
    return;
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