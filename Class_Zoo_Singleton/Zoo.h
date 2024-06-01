#ifndef ZOO_H
#define ZOO_H
#include <iostream>
#include "Animal.h"
#include "Bear.h"
#include "Elephant.h"
#include "Giraffe.h"
#include "Lion.h"
#include "Tiger.h"

class Zoo
{
    private:
        Zoo(int);
        static Zoo* s_ptr;
        const int m_size;
        Animal** m_animals; 
        ~Zoo();
    public:
        Zoo(const Zoo&) = delete;
        Zoo& operator=(const Zoo&) = delete;
        static Zoo* getZoo(int);
        void printZoo() const;
        static void deleteZoo();
};

#endif //A_H
