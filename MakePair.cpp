#include <iostream>
#include <utility>

template<typename T1 , typename T2>
std::pair<std::decay_t<T1> , std::decay_t<T2>> make_pair(T1&& first , T2&& second) // decay_t to remove references, constness
{
    return std::pair<std::decay_t<T1> , std::decay_t<T2>>({std::forward<T1>(first) , std::forward<T2>(second)});
}

int main()
{
    std::pair<int , double> p = make_pair(2 , 10.1);
    std::cout << p.first << " " << p.second << std::endl;
    return 0;
}