#include <iostream>
#include <memory>

int main() {
    const int rows = 3;
    const int cols = 4;
    std::shared_ptr<std::shared_ptr<int[]>[]> mat = std::make_shared<std::shared_ptr<int[]>[]>(rows); 
    for (int i = 0; i < rows; ++i) 
    {
        mat[i] = std::make_shared<int[]>(cols);
    }
    
    auto init = [](std::shared_ptr<std::shared_ptr<int[]>[]> mat , int rows , int cols) 
    {
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = i * cols + j;
            }
        }
    };

    auto print = [](std::shared_ptr<std::shared_ptr<int[]>[]> mat , int rows , int cols) 
    {
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
            std::cout << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    };
    
    init(mat, rows, cols);
    print(mat, rows, cols);
    return 0;
}
