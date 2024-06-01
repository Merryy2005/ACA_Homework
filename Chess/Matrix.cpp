#include "Matrix.h"

Matrix::Matrix() : m_ptr(nullptr) , m_row(0) , m_col(0)
{

}

Matrix::Matrix(int row , int col) : m_row(row) , m_col(col) , m_ptr(new int*[row])
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

void Matrix::printMatrix()
{
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            std::cout << m_ptr[i][j] <<" ";
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