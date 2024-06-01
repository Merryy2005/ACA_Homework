#ifndef ELEPHANT_H
#define ELEPHANT_H

#include <iostream>
#include "Animal.h"

class Elephant:public Animal
{
    public:
        Elephant();
        explicit Elephant(int, double);
        explicit Elephant(const Elephant&);
        explicit Elephant(Elephant&&);
        Elephant& operator= (const Elephant&);
        Elephant& operator= (Elephant&&);
        virtual void voice() const override;
        virtual std::string name() const override;
        ~Elephant();
};

#endif //ELEPHANT_H