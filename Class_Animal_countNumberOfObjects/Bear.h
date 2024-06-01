#ifndef BEAR_H
#define BEAR_H

#include <iostream>
#include "Animal.h"

class Bear:public Animal
{
    public:
        Bear();
        Bear(int, double);
        Bear(const Bear&);
        virtual void voice() const override;
        ~Bear();
};

#endif //BEAR_H