#ifndef TIGER_H
#define TIGER_H

#include <iostream>
#include "Animal.h"

class Tiger:public Animal
{
    public:
        Tiger();
        virtual void voice() override;
        ~Tiger();
};

#endif //TIGER_H