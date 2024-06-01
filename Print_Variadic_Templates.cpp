#include <iostream>

//base case
void print()
{
    std::cout << "" << std::endl;
}

template<typename T , typename... Types>
void print(T var1 , Types... vars)
{
    std::cout << var1 << std::endl;
    print(vars...);
}

int main()
{
    print(1.4 , 830 , "hello world" , -4);
}