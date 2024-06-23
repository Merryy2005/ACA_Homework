#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

int main() {
    std::function<std::function<int(int)>(int)> mult = [](int a) -> std::function<int(int)>
    {
        return [a](int b) -> int // another lamda function
        {
            return a*b;
        };
    };
    std::cout << mult(5)(6);
    return 0;
}
