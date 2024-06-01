#ifndef A_H
#define A_H

#include <iostream>

class A
{
    private:
        int m_cnt;
    public:
        A();
        A(int);
        A(const A&);
        A& operator++(); //prefix
        A operator++(int); //postfix
        friend std::ostream& operator<< (std::ostream& , const A&); 
        ~A();
};

#endif //A_H