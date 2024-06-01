#include <iostream>

int calcSum(int** matrix ,const int& n)
{
    int s = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if((i + j) >= n)
            {
                s += matrix[i][j];
            }
        }
    }
    return s;
}

int main()
{
    int n;
    std::cin >> n;
    int** matrix = nullptr;
    try
    {
        matrix = (int**)malloc(n * sizeof(int*));
        if(matrix == nullptr)
        {
            throw std::bad_alloc();
        }
        for(int i = 0 ; i < n ; i++)
        {
            matrix[i] = (int*)malloc(n * sizeof(int));
            if(matrix[i] == nullptr){
                throw std::bad_alloc();
            }
        }
    }
    catch(const std::bad_alloc& e) 
    {
        std::cout << "Not enough memory "<< std::endl;
        return 1;
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << calcSum(matrix , n) << std::endl;
    for(int i = 0 ; i < n ; i++)
    {
        free(matrix[i]);
        matrix[i] = nullptr;
    }
    free(matrix);
    matrix = nullptr; 
    return 0;
}