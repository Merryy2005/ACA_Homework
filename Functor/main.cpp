#include "A.h"

void f(const A& functor)
{
    functor();
    return;
}

int f1(const A& functor)
{
    return functor(1);
}

int f2(const A& functor)
{
    return functor(2,3);
}

int main()
{
    A a;
    f(a);
    std::cout << f1(a) << std::endl;
    std::cout << f2(a) << std::endl;
    return 0;
}