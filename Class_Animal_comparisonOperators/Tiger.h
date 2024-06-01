#ifndef TIGER_H
#define TIGER_H

#include <iostream>
#include "Animal.h"

class Tiger:public Animal
{
    public:
        Tiger();
        explicit Tiger(int, double);
        explicit Tiger(const Tiger&);
        explicit Tiger(Tiger&&);
        Tiger& operator= (const Tiger&);
        Tiger& operator= (Tiger&&);
        virtual void voice() const override;
        virtual std::string name() const override;
        ~Tiger();
};

#endif //TIGER_H