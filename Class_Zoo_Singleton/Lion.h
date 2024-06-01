#ifndef LION_H
#define LION_H

#include <iostream>
#include "Animal.h"

class Lion:public Animal
{
    private:
        Lion(int, double);
        ~Lion();
    public:
        Lion(const Lion&) = delete;
        static Animal* createObj(int , double);
        virtual void voice() const override;
};

#endif //LION_H