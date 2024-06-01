#include <iostream>
#include <cstdlib> 
#include <ctime>

void transposeMatrix(int** matrix , int** matrix1 , const int& n , const int& m)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            matrix1[i][j] = matrix[j][i];
        }
    }
    return;
}

void printMatrix(int** matrix , const int& n , const int& m)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return;
}

int main()
{
    srand(time(0));
    int m , n;
    std::cin >> m >> n;
    int** matrix = new int*[m];
    for(int i = 0 ; i < m ; i++)
    {
        matrix[i] = new int[n];
    }
    int** matrix1 = new int*[n];
    for(int i = 0 ; i < n ; i++)
    {
        matrix1[i] = new int[m];
    }
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            matrix[i][j] = 1 + rand()%100;
        }
    }
    transposeMatrix(matrix , matrix1 , n , m);
    std::cout << "Initial Matrix" << std::endl;
    printMatrix(matrix , m , n);
    std::cout << "Transposed Matrix" << std::endl;
    printMatrix(matrix1 , n , m);
    for(int i = 0 ; i < m ; i++)
    {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    for(int i = 0 ; i < n ; i++)
    {
        delete[] matrix1[i];
        matrix1[i] = nullptr;
    }
    delete[] matrix;
    delete[] matrix1;
    matrix = nullptr;
    matrix1 =nullptr;
    return 0;
}