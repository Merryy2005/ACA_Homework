#ifndef ELEPHANT_H
#define ELEPHANT_H

#include <iostream>
#include "Animal.h"

class Elephant:public Animal
{
    private:
        Elephant(int, double);
        ~Elephant();
    public:
        Elephant(const Elephant&) = delete;
        static Animal* createObj(int , double);
        virtual void voice() const override;
};

#endif //ELEPHANT_H