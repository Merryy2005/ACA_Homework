#ifndef GIRAFFE_H
#define GIRAFFE_H

#include <iostream>
#include "Animal.h"

class Giraffe:public Animal
{
    public:
        Giraffe();
        virtual void voice() override;
        ~Giraffe();
};

#endif //GIRAFFE_H