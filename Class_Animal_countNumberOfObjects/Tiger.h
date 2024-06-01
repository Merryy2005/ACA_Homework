#ifndef TIGER_H
#define TIGER_H

#include <iostream>
#include "Animal.h"

class Tiger:public Animal
{
    public:
        Tiger();
        Tiger(int, double);
        Tiger(const Tiger&);
        virtual void voice() const override;
        ~Tiger();
};

#endif //TIGER_H