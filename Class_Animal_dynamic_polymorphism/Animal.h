#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
    protected:
        int m_age;
        double m_weight;
    public:
        Animal();
        Animal(int, double);
        Animal(const Animal&);
        void print() const;
        virtual void voice() const = 0;
        virtual ~Animal();
};

#endif //ANIMAL_H