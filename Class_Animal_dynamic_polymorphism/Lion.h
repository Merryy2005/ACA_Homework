#ifndef LION_H
#define LION_H

#include <iostream>
#include "Animal.h"

class Lion:public Animal
{
    public:
        Lion();
        Lion(int, double);
        Lion(const Lion&);
        virtual void voice() const override;
        ~Lion();
};

#endif //LION_H