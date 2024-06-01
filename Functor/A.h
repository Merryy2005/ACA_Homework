#ifndef A_H
#define A_H

#include <iostream>

class A
{
    public:
        void operator() () const;
        int operator() (int) const;
        int operator() (int , int) const;
};

#endif //A_H