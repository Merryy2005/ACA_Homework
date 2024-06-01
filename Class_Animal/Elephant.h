#ifndef ELEPHANT_H
#define ELEPHANT_H

#include <iostream>
#include "Animal.h"

class Elephant:public Animal
{
    public:
        Elephant();
        virtual void voice() override;
        ~Elephant();
};

#endif //ELEPHANT_H