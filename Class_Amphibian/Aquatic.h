#ifndef AQUATIC_H
#define AQUATIC_H

#include <iostream>
#include <string>
#include "Animal.h"

class Aquatic : public virtual Animal
{
    protected:
        double m_temp; // water temperature
    public:
        Aquatic();
        Aquatic(double , int , int , std::string , double);
        void print() const;
        ~Aquatic();
};

#endif //AQUATIC_H