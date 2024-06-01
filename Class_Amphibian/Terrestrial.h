#ifndef TERRESTRIAL_H
#define TERRESTRIAL_H

#include <iostream>
#include <string>
#include "Animal.h"

class Terrestrial : public virtual Animal
{
    protected:
        std::string m_climate;
    public:
        Terrestrial();
        Terrestrial(double , int , int , std::string , std::string);
        void print() const;
        ~Terrestrial();
};

#endif //TERRESTRIAL_H