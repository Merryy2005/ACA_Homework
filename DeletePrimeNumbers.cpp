#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14};
    vec.erase(std::remove_if(vec.begin() , vec.end() , [](int n) -> bool{ if (n <= 1) return false;
        for (int i = 2; i <= std::sqrt(n); ++i) if (n % i == 0) return false; return true;}) , vec.end());
    std::for_each(vec.begin(), vec.end(), [](int elem) -> void { std::cout << elem << " ";});
    std::cout << std::endl;
    return 0;
}
