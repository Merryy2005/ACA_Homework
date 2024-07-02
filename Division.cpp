#include <iostream>

int divide(int a, int b)
{
    if(a < b)
    {
        return 0;
    }
    int c = 1;
    while(b * c < a)
    {
        c *= 2;
    }
    if(b * c == a)
    {
        return c;
    }
    int l = c / 2;
    int r = c - 1;
    while(l < r)
    {
        int m = (l + r) / 2;
        if(b * m == a)
        {
            return m;
        }
        if(b * m < a)
        {
            if(b * (m+1) > a)
            {
                return m;
            }
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return l;
}

int main()
{
    int a , b;
    std::cin >> a >> b;
    while(a != 0)
    {
        std::cout << divide(a,b) << std::endl;
        std::cin >> a >> b;
    }
    return 0;
}