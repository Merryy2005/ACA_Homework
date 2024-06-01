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
        Lion(Lion&&);
        Lion& operator= (const Lion&);
        Lion& operator= (Lion&&);
        virtual void voice() const override;
        virtual std::string name() const override;
        ~Lion();
};

#endif //LION_H