#include <iostream>
#include <vector>

template<class InputIt, class Func>
void for_each(InputIt first, InputIt last, Func f)
{
    for (; first != last; ++first)
        f(*first);
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    for_each(vec.begin(), vec.end(), [](const int& elem) {
        std::cout << elem << " ";
    });
    std::cout << std::endl;
    
    return 0;
}
