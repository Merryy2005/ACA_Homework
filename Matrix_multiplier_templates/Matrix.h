#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <type_traits>
#include <random>

template <typename T>

class Matrix
{
    private:
        int m_row;
        int m_col;
        T** m_ptr;
        int getNumberRows(const std::string&) const;
        int getNumberColumns(const std::string&) const;
    public:
        Matrix();
        Matrix(int , int);
        Matrix(const Matrix&);
        Matrix(Matrix&&);
        Matrix(const std::string&);
        Matrix& operator= (const Matrix&);
        Matrix& operator= (Matrix&&);
        Matrix operator+(const Matrix&) const;
        Matrix operator*(const Matrix&) const;
        Matrix& operator++();
        Matrix operator++(int);
        void write_to_file(const std::string&) const;
        template <typename U>
        friend std::ostream& operator<< (std::ostream& , const Matrix<U>&);
        template <typename U>
        friend std::istream& operator>> (std::istream& , Matrix<U>&);
        ~Matrix();
};

template <typename T>
Matrix<T>::Matrix() : m_row(0) , m_col(0) , m_ptr(nullptr)
{

}

template<>
Matrix<std::string>::Matrix(int row , int col) : m_row(row), m_col(col), m_ptr(new std::string*[m_row])
{
    for(int i = 0 ; i < m_row ; i++)
    {
        m_ptr[i] = new std::string[m_col];
    }
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            m_ptr[i][j] = "";
            for (int k = 0; k < 5; k++)
            {
                m_ptr[i][j] += charset[rand() % (sizeof(charset) - 1)];
            }
        }
    }
}

template <typename T>
Matrix<T>::Matrix(int row, int col) : m_row(row), m_col(col), m_ptr(new T*[m_row])
{
    for(int i = 0 ; i < m_row ; i++)
    {
        m_ptr[i] = new T[m_col];
    }
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            if (std::is_integral<T>::value) 
            {
                m_ptr[i][j] = rand() % 100; 
            } 
            else if (std::is_floating_point<T>::value) 
            {
                m_ptr[i][j] = static_cast<T>(rand()) / static_cast<T>(RAND_MAX) * 100.0;
            } 
            else 
            {
                throw std::invalid_argument("Randomize is not supported for this type");
            }
        }
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other) :m_row(other.m_row) , m_col(other.m_col) , m_ptr(new T*[m_row]) 
{
    for(int i = 0 ; i < m_row ; i++){
        m_ptr[i] = new T[m_col];
    }
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            m_ptr[i][j] = other.m_ptr[i][j];
        }
    }
}

template <typename T>
Matrix<T>::Matrix(Matrix<T>&& other) : m_row(other.m_row)  , m_col(other.m_col) , m_ptr(other.m_ptr)
{
    other.m_ptr = nullptr;
    other.m_row = 0;
    other.m_col = 0;
}

template <typename T>
Matrix<T>::Matrix(const std::string& filename) : m_row(getNumberRows(filename)) , m_col(getNumberColumns(filename)) , m_ptr(new T*[m_row])
{
    for(int i = 0 ; i < m_row ; i++)
    {
        m_ptr[i] = new T[m_col];
    }
    std::ifstream fin(filename);   
    if (!fin.is_open()) 
    {
        throw std::runtime_error("Error opening file");
    }
    std::string line;
    int i = 0;
    while (std::getline(fin, line)) 
    {
        std::stringstream ss(line);
        for(int j = 0 ; j < m_col ; j++)
        {
            ss >> m_ptr[i][j];
        }
        i++;
    }
    fin.close();
}

template <typename T>
int Matrix<T>::getNumberRows(const std::string& filename) const
{
    std::ifstream fin(filename);   
    if (!fin.is_open()) 
    {
        throw std::runtime_error("Error opening file");
    }
    std::string line;
    int rows = 0;
    while (std::getline(fin, line)) 
    {
        rows++;
    }
    if(rows == 0)
    {
        throw std::runtime_error("File is empty");
    }
    return rows;
}

template <typename T>
int Matrix<T>::getNumberColumns(const std::string& filename) const
{
    std::ifstream fin(filename);   
    if (!fin.is_open()) 
    {
        throw std::runtime_error("Error opening file");
    }
    std::string line;
    int cols = 0;
    T num;
    std::getline(fin, line);
    std::stringstream ss(line);
    while (ss >> num) 
    {
        cols++;
    }
    if(cols == 0)
    {
        throw std::runtime_error("File is empty");
    }
    return cols;
}

template <typename T>
Matrix<T>& Matrix<T>::operator= (const Matrix<T>& other)
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
        m_ptr = new T*[m_row];
        for(int i = 0 ; i < m_row ; i++){
            m_ptr[i] = new T[m_col];
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

template <typename T>
Matrix<T>& Matrix<T>::operator= (Matrix<T>&& other)
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
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
        other.m_col = 0;
        other.m_row = 0;
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+ (const Matrix<T>& other) const
{
    Matrix temp(m_row , m_col);
    if(m_row == other.m_row && m_col == other.m_col)
    {
        for(int i = 0 ; i < m_row ; i++)
        {
            for(int j = 0 ; j < m_col ; j++)
            {
                temp.m_ptr[i][j] = this->m_ptr[i][j] + other.m_ptr[i][j];
            }
        }
    }
    else
    {
        throw std::invalid_argument("Can't do addition");
    }
    return std::move(temp);
}

template<>
Matrix<std::string> Matrix<std::string>::operator*(const Matrix<std::string>& other) const
{
    throw std::invalid_argument("Can't do multiplication for strings");   
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const
{
    if(m_col != other.m_row)
    {
        throw std::invalid_argument("Matrix dimensions are incompatible for multiplication");    
    }
    Matrix temp(m_row , other.m_col);
    for(int i = 0 ; i < temp.m_row ; i++)
    {
        for(int j = 0 ; j < temp.m_col ; j++)
        {
            temp.m_ptr[i][j] = T();
            for(int k = 0 ; k < m_col ; k++)
            {
                temp.m_ptr[i][j] += m_ptr[i][k] * other.m_ptr[k][j];
            }
        }
    }
    return std::move(temp);
}

template <typename T>
Matrix<T>& Matrix<T>::operator++()
{
    if(std::is_same<T , std::string>::value)
    {
        throw std::invalid_argument("Can't do +++operator");   
    }
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            m_ptr[i][j]+=3;
        }
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator++(int)
{
    if(std::is_same<T , std::string>::value)
    {
        throw std::invalid_argument("Can't do +++operator");   
    }
    Matrix temp(*this);
    ++(*this);
    return temp;
}

template <typename T>
void Matrix<T>::write_to_file(const std::string& filename) const 
{
        std::ofstream fout(filename);
        if (!fout) 
        {
            throw std::runtime_error("Cannot open the file");
            return;
        }
        for (int i = 0 ; i < m_row ; i++) 
        {
            for (int j = 0 ; j < m_col ; j++) 
            {
                fout << m_ptr[i][j] << " ";
            }
            fout << std::endl;
        }
        fout.close();
        return;
}

template <typename U>
std::ostream& operator<< (std::ostream& os, const Matrix<U>& mtrx)
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

template <typename U>
std::istream& operator>> (std::istream& is, Matrix<U>& mtrx)
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

template <typename T>
Matrix<T>::~Matrix()
{
    for(int i = 0 ; i < m_row ; i++)
    {
        delete[] m_ptr[i];
        m_ptr[i] = nullptr;
    }
    delete[] m_ptr;
    m_ptr = nullptr;
}

#endif //MATRIX_H