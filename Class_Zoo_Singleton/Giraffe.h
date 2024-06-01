#ifndef GIRAFFE_H
#define GIRAFFE_H

#include <iostream>
#include "Animal.h"

class Giraffe:public Animal
{
    private:
        Giraffe(int, double);
        ~Giraffe();
    public:
        Giraffe(const Giraffe&) = delete;
        static Animal* createObj(int , double);
        virtual void voice() const override;
};

#endif //GIRAFFE_H