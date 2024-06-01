#include <iostream>
#include <cstdlib> 
#include <ctime>

void swap(int& a , int& b){
    int c = b;
    b = a;
    a = c;
    return;
}

void transposeMatrix(int* matrix , const int& m)
{
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            swap(matrix[i*m + j] , matrix[j*m + i]);
        }
    }
    return;
}

void printMatrix(int* matrix , const int& m)
{
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            std::cout << matrix[i*m + j] << " ";
        }
        std::cout << std::endl;
    }
    return;
}

int main()
{
    srand(time(0));
    int m;
    std::cin >> m;
    int* matrix = new int[m * m];
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            matrix[i*m + j] = 1 + rand()%100;
        }
    }
    std::cout << "Initial Matrix" << std::endl;
    printMatrix(matrix , m);
    transposeMatrix(matrix , m);
    std::cout << "Transposed Matrix" << std::endl;
    printMatrix(matrix , m);
    delete[] matrix;
    matrix = nullptr;
    return 0;
}