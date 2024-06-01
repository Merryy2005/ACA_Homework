#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Matrix
{
    private:
        int m_row;
        int m_col;
        int** m_ptr;
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
        friend std::ostream& operator<< (std::ostream& , const Matrix&);
        friend std::istream& operator>> (std::istream& , Matrix&);
        ~Matrix();
};

#endif //MATRIX_H