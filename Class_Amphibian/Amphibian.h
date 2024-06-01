#ifndef AMPHIBIAN_H
#define AMPHIBIAN_H

#include <iostream>
#include <string>
#include "Terrestrial.h"
#include "Aquatic.h"

class Amphibian : public Terrestrial , public Aquatic
{
    public:
        Amphibian();
        Amphibian(double , int , int , std::string , std::string , double);
        void print() const;
        ~Amphibian();
};

#endif //AMPHIBIAN_H