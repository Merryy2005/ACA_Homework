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
        Bear(Bear&&);
        Bear& operator= (const Bear&);
        Bear& operator= (Bear&&);
        virtual void voice() const override;
        virtual std::string name() const override;
        ~Bear();
};

#endif //BEAR_H