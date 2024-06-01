#ifndef GIRAFFE_H
#define GIRAFFE_H

#include <iostream>
#include "Animal.h"

class Giraffe:public Animal
{
    public:
        Giraffe();
        Giraffe(int, double);
        Giraffe(const Giraffe&);
        virtual void voice() const override;
        ~Giraffe();
};

#endif //GIRAFFE_H