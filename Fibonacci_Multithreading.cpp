#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mtx;

void Fibonacci(std::vector<int>& v , int n , int& ans)
{
    mtx.lock();
    if(v[n] == -1)
    {

        for(int i = 2 ; i <= n ; i++)
        {
            if(v[i] == -1)
            {
                v[i] = v[i-1] + v[i-2];
            }
        }
    }
    mtx.unlock();
    ans = v[n];
    return;
}

int main()
{
    std::vector<int> v(100 , -1);    
    v[0] = 0;
    v[1] = 1;
    int ind1 = 10;
    int ind2 = 4;
    int ind3 = 15;
    int ans1 , ans2 , ans3;
    std::thread t1(Fibonacci , std::ref(v) , ind1 , std::ref(ans1));
    std::thread t2(Fibonacci , std::ref(v) , ind2 , std::ref(ans2));
    std::thread t3(Fibonacci , std::ref(v) , ind3 , std::ref(ans3));
    t1.join();
    t2.join();
    t3.join();
    std::cout << ans1 << " " << ans2 << " " << ans3 << std::endl;
    return 0;
}