#include <iostream>

template<unsigned int T>
struct Fibonacci
{
    static const long res = Fibonacci<T-1>::res + Fibonacci<T-2>::res;
};

template<>
struct Fibonacci<0>
{
    static const long res = 0;
};

template<>
struct Fibonacci<1>
{
    static const long res = 1;
};

int main()
{
    std::cout << Fibonacci<0>::res << " ";
    std::cout << Fibonacci<1>::res << " ";
    std::cout << Fibonacci<2>::res << " ";
    std::cout << Fibonacci<3>::res << " ";
    std::cout << Fibonacci<4>::res << " ";
    std::cout << Fibonacci<5>::res << " ";
    std::cout << Fibonacci<6>::res << " ";
    std::cout << Fibonacci<7>::res << " ";
    std::cout << Fibonacci<8>::res << " ";
    std::cout << Fibonacci<9>::res << " ";
    std::cout << Fibonacci<10>::res << " ";

    return 0;
}