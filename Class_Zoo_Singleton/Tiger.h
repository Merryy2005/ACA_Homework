#ifndef TIGER_H
#define TIGER_H

#include <iostream>
#include "Animal.h"

class Tiger:public Animal
{
    private:
        Tiger(int, double);
        ~Tiger();
    public:
        Tiger(const Tiger&) = delete;
        static Animal* createObj(int , double);
        virtual void voice() const override;
};

#endif //TIGER_H