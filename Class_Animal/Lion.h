#ifndef LION_H
#define LION_H

#include <iostream>
#include "Animal.h"

class Lion:public Animal
{
    public:
        Lion();
        virtual void voice() override;
        ~Lion();
};

#endif //LION_H