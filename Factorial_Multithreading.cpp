#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mtx;

void Factorial(std::vector<long long>& v, int n, long long& ans)
{
    mtx.lock();
    if (v[n] == -1)
    {
        for (int i = 2; i <= n; i++)
        {
            if (v[i] == -1)
            {
                v[i] = v[i-1] * i;
            }
        }
    }
    mtx.unlock();
    ans = v[n];
    return;
}

int main()
{
    std::vector<long long> v(100, -1);    
    v[0] = 1;
    v[1] = 1;
    
    int f1 = 10;
    int f2 = 4;
    int f3 = 15;
    
    long long ans1 = 0, ans2 = 0, ans3 = 0;
    
    std::thread t1(Factorial, std::ref(v), f1, std::ref(ans1));
    std::thread t2(Factorial, std::ref(v), f2, std::ref(ans2));
    std::thread t3(Factorial, std::ref(v), f3, std::ref(ans3));
    
    t1.join();
    t2.join();
    t3.join();
    
    std::cout << ans1 << " " << ans2 << " " << ans3 << std::endl;
    
    return 0;
}
