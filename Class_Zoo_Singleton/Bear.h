#ifndef BEAR_H
#define BEAR_H

#include <iostream>
#include "Animal.h"

class Bear:public Animal
{
    private:
        Bear(int, double);
        ~Bear();
    public:
        Bear(const Bear&) = delete;
        static Animal* createObj(int , double);
        virtual void voice() const override;
};

#endif //BEAR_H