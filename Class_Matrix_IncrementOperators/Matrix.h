#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix
{
    private:
        int** m_ptr;
        int m_row;
        int m_col;
    public:
        Matrix();
        Matrix(int , int);
        Matrix(const Matrix&);
        Matrix& operator= (const Matrix&);
        Matrix& operator++();
        Matrix operator++(int);
        friend std::ostream& operator<< (std::ostream& , const Matrix&);
        friend std::istream& operator>> (std::istream& , Matrix&);
        ~Matrix();
};

#endif //MATRIX_H