#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
    protected:
        double m_weight;
        int m_height;
        int m_age;
        std::string m_color;
    public:
        Animal();
        Animal(double , int , int , std::string);
        void print() const;
        ~Animal();
};

#endif //ANIMAL_H