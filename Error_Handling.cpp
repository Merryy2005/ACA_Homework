#include <iostream>
#include <string>

class A
{
    private:
        int a;
    public:
        A(int a) : a(a)
        {}
        ~A()
        {
            if(a == 0)
            {
                throw std::string("Exception caught"); 
            }
        }
};

int main()
{
    try
    {
        A obj(0);
        A obj1(1);
    }
    catch (const char* s)
    {
        std::cout << s << std::endl;
    }
    return 0;
}
