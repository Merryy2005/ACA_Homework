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
        Giraffe(Giraffe&&);
        Giraffe& operator= (const Giraffe&);
        Giraffe& operator= (Giraffe&&);
        virtual void voice() const override;
        virtual std::string name() const override;
        ~Giraffe();
};

#endif //GIRAFFE_H