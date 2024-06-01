#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix
{
    protected:
        int** m_ptr;
        int m_row;
        int m_col;
    public:
        Matrix();
        Matrix(int , int);
        void printMatrix();
        ~Matrix();
};

#endif //MATRIX_H