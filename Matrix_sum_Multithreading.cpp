#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

long long sum(const std::vector<std::vector<int>>& v, int s, int e, int col) 
{
    long long sm = 0;
    for (int i = s; i < e; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            sm += v[i][j];
        }
    }
    return sm;
}

int main() {
    const int row = 10000;
    const int col = 10000; 
    std::vector<std::vector<int>> v(row, std::vector<int>(col, 1));
    
    auto start = std::chrono::high_resolution_clock::now();
    std::thread t1(sum , std::ref(v) , 0 , row/2 , col);
    std::thread t2(sum , std::ref(v) , row/10 , row/5 , col);
    std::thread t3(sum , std::ref(v) , row/5 , 3*row/10 , col);
    std::thread t4(sum , std::ref(v) , 3*row/10 , 2*row/5 , col);
    std::thread t5(sum , std::ref(v) , 2*row/5 , row/2 , col);
    std::thread t6(sum , std::ref(v) , row/2 , 6*row/10 , col);
    std::thread t7(sum , std::ref(v) , 6*row/10 , 7*row/10 , col);
    std::thread t8(sum , std::ref(v) , 7*row/10 , 8*row/10 , col);
    std::thread t9(sum , std::ref(v) , 8*row/10 , 9*row/10 , col);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    sum(v , 9*row/10 , row , col);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;
    return 0;
}
