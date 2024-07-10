#ifndef A_H
#define A_H

#include <iostream>

class A 
{
    private:
        int a;
    public:
        A(int a) : a(a) 
        {
            
        }
        ~A() 
        {

        }
        void display() const 
        {
            std::cout << "class A" << std::endl;
        }
        friend std::ostream& operator<<(std::ostream& os, const A& obj) 
        {
            os << obj.a;
            return os;
        }
};

#endif // A_H
