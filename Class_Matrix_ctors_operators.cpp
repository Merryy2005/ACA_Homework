#include <iostream>
#include <cstdlib> 
#include <ctime>

class Matrix{
    private:
        int** ptr;
        int m;
        int n;
    public:
        Matrix()
        {
            ptr = NULL;
            m = 0;
            n = 0;
        }
        Matrix(int m , int n)
        {
            this -> m = m;
            this -> n = n;
            ptr = new int*[m];
            for(int i = 0 ; i < m ; i++){
                ptr[i] = new int[n];
            }
            for(int i = 0 ; i < m ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    ptr[i][j] = 1 + rand()%100;
                }
            }
        }
        Matrix(const Matrix& other)
        {
            m = other.m;
            n = other.n;
            ptr = new int*[m];
            for(int i = 0 ; i < m ; i++)
            {
                ptr[i] = new int[n];
            }
            for(int i = 0 ; i < m ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    ptr[i][j] = other.ptr[i][j];
                }
            }
        }
        Matrix& operator= (const Matrix& other){
            if(this != &other)
            {
                for(int i = 0 ; i < m ; i++)
                {
                    delete[] ptr[i];
                    ptr[i] = nullptr;
                }
                delete[] ptr;
                ptr = nullptr;
                m = other.m;
                n = other.n;
                ptr = new int*[m];
                for(int i = 0 ; i < m ; i++)
                {
                    ptr[i] = new int[n];
                }
                for(int i = 0 ; i < m ; i++)
                {
                    for(int j = 0 ; j < n ; j++)
                    {
                        ptr[i][j] = other.ptr[i][j];
                    }
                }
            }
            return *this;
        }
        const Matrix operator+ (const Matrix& other)
        {
            try
            {
                if(m == other.m && n == other.n){
                    Matrix result(m , n);
                    for(int i = 0 ; i < m ; i++)
                    {
                        for(int j = 0 ; j < n ; j++)
                        {
                            result.ptr[i][j] = ptr[i][j] + other.ptr[i][j];
                        }
                    }
                    return result;
                }
                else{
                    throw "Can't do the addition";
                }
            }
            catch(const char* s)
            {
                Matrix result;
                std::cout << s << std::endl;
                return result;
            }
        }
        void printMatrix(){
            for(int i = 0 ; i < m ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    std::cout << ptr[i][j] <<" ";
                }
                std::cout << std::endl;
            }
            return;
        }
        ~Matrix()
        {
            for(int i = 0 ; i < m ; i++)
            {
                delete[] ptr[i];
                ptr[i] = nullptr;
            }
            delete[] ptr;
            ptr = nullptr;
        }
};

int main()
{
    srand(time(0));
    int m , n;
    std::cin >> m >> n;
    Matrix myMatrix(m , n);
    std::cout << "Matrix" << std::endl;
    myMatrix.printMatrix();
    Matrix myMatrix1(m , n);
    std::cout << "Matrix1" << std::endl;
    myMatrix1.printMatrix();
    Matrix myMatrix2 = myMatrix + myMatrix1;
    std::cout << "Matrix2" << std::endl;
    myMatrix2.printMatrix();
    myMatrix1 = myMatrix;
    std::cout << "Updated Matrix1" << std::endl;
    myMatrix1.printMatrix();
    Matrix myMatrix3(4,3);
    std::cout << "Matrix3" << std::endl;
    myMatrix3.printMatrix();
    myMatrix2 = myMatrix3 + myMatrix1;
    return 0;
}