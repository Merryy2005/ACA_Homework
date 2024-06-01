#ifndef LION_H
#define LION_H

#include <iostream>
#include "Animal.h"

class Lion:public Animal
{
    public:
        Lion();
        explicit Lion(int, double);
        explicit Lion(const Lion&);
        explicit Lion(Lion&&);
        Lion& operator= (const Lion&);
        Lion& operator= (Lion&&);
        virtual void voice() const override;
        virtual std::string name() const override;
        ~Lion();
};

#endif //LION_H