#ifndef A_H
#define A_H
#include <iostream>

class A
{
    private:
        static A* s_ptr;
        int m_x;
        A(int);
    public:
        A(const A&) = delete;
        A& operator=(const A&) = delete;
        static A* createObj(int);
        void printObj();
        static void deleteObj();
        ~A();
};

#endif //A_H
