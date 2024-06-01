#ifndef BEAR_H
#define BEAR_H

#include <iostream>
#include "Animal.h"

class Bear:public Animal
{
    public:
        Bear();
        virtual void voice() override;
        ~Bear();
};

#endif //BEAR_H