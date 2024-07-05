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
            try
            {
                if(a == 0)
                {
                    throw std::runtime_error("Exception found in destructor");
                    std::terminate(); 
                }
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << std::endl;
                std::terminate(); 
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
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}