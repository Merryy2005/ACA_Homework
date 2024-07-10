#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix
{
    public:
        enum class Color
        {
            black,
            white
        };
    protected:
        int m_row;
        int m_col;
        Color** m_ptr;
    public:
        Matrix();
        Matrix(int, int);
        Matrix& operator=(const Matrix&);
        void printMatrix();
        ~Matrix();
};

#endif // MATRIX_H