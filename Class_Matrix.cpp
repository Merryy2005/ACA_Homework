#include <iostream>
#include <cstdlib> 
#include <ctime>

class Matrix{
    private:
        int** ptr = NULL;
        int m = 0;
        int n = 0;
    public:
        void inputDimensions()
        {
            std::cin >> m >> n;
            return;
        }
        void setDimensions(const int& row , const int& col)
        {
            m = row;
            n = col;
            return;
        }
        int getRow()
        {
            return m;
        }
        int getCol()
        {
            return n;
        }
        void createMatrix()
        {
            ptr = new int*[m];
            for(int i = 0 ; i < m ; i++)
            {
                ptr[i] = new int[n];
            }
            return;
        }
        void initializeMatrix()
        {
            for(int i = 0 ; i < m ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    ptr[i][j] = 1 + rand()%100;
                }
            }
        }
        void deleteMatrix()
        {
            for(int i = 0 ; i < m ; i++)
            {
                delete[] ptr[i];
                ptr[i] = nullptr;
            }
            delete[] ptr;
            ptr = nullptr;
            return;
        }
        void transposeMatrix(const Matrix& matrix1)
        {
            for(int i = 0 ; i < n ; i++)
            {
                for(int j = 0 ; j < m ; j++)
                {
                    matrix1.ptr[i][j] = ptr[j][i];
                }
            }
            return;
        }
        void printMatrix()
        {
            for(int i = 0 ; i < m ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    std::cout << ptr[i][j] << " ";
                }
                std::cout << std::endl;
            }
            return;
        }
};

int main()
{
    srand(time(0));
    Matrix matrix , matrix1;
    matrix.inputDimensions();
    matrix1.setDimensions(matrix.getCol() , matrix.getRow());
    matrix.createMatrix();
    matrix1.createMatrix();
    matrix.initializeMatrix();
    matrix.transposeMatrix(matrix1);
    std::cout << "Initial Matrix" << std::endl;
    matrix.printMatrix();
    std::cout << "Transposed Matrix" << std::endl;
    matrix1.printMatrix();
    matrix.deleteMatrix();
    matrix1.deleteMatrix();
    return 0;
}