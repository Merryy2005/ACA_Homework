#include "Matrix.h"

Matrix::Matrix() : m_row(0) , m_col(0) , m_ptr(nullptr)
{

}

Matrix::Matrix(int row , int col) : m_row(row) , m_col(col) , m_ptr(new int*[m_row])
{
    for(int i = 0 ; i < m_row ; i++){
        m_ptr[i] = new int[m_col];
    }
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            m_ptr[i][j] = rand() % 100;
        }
    }

}

Matrix::Matrix(const Matrix& other) :m_row(other.m_row) , m_col(other.m_col) , m_ptr(new int*[m_row]) 
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

Matrix::Matrix(Matrix&& other) : m_row(other.m_row)  , m_col(other.m_col) , m_ptr(other.m_ptr)
{
    other.m_ptr = nullptr;
    other.m_row = 0;
    other.m_col = 0;
}

Matrix::Matrix(const std::string& filename) : m_row(getNumberRows(filename)) , m_col(getNumberColumns(filename)) , m_ptr(new int*[m_row])
{
    for(int i = 0 ; i < m_row ; i++)
    {
        m_ptr[i] = new int[m_col];
    }
    std::ifstream fin(filename);   
    if (!fin.is_open()) 
    {
        throw std::runtime_error("Error opening file");
    }
    std::string line;
    int i = 0;
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        for(int j = 0 ; j < m_col ; j++)
        {
            ss >> m_ptr[i][j];
        }
        i++;
    }
    fin.close();
}

int Matrix::getNumberRows(const std::string& filename) const
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

int Matrix::getNumberColumns(const std::string& filename) const
{
    std::ifstream fin(filename);   
    if (!fin.is_open()) 
    {
        throw std::runtime_error("Error opening file");
    }
    std::string line;
    int cols = 0;
    int num;
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

Matrix& Matrix::operator= (Matrix&& other)
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

Matrix Matrix::operator+ (const Matrix& other) const
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

Matrix Matrix::operator*(const Matrix& other) const
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
            temp.m_ptr[i][j] = 0;
            for(int k = 0 ; k < m_col ; k++)
            {
                temp.m_ptr[i][j] += m_ptr[i][k] * other.m_ptr[k][j];
            }
        }
    }
    return temp;
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

void Matrix::write_to_file(const std::string& filename) const 
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