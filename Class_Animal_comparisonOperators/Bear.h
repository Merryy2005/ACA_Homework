#ifndef BEAR_H
#define BEAR_H

#include <iostream>
#include "Animal.h"

class Bear:public Animal
{
    public:
        Bear();
        explicit Bear(int, double);
        explicit Bear(const Bear&);
        explicit Bear(Bear&&);
        Bear& operator= (const Bear&);
        Bear& operator= (Bear&&);
        virtual void voice() const override;
        virtual std::string name() const override;
        ~Bear();
};

#endif //BEAR_H