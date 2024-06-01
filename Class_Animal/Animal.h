#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
    public:
        Animal();
        virtual void voice();
        virtual ~Animal();
};

#endif //ANIMAL_H