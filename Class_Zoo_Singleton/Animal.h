#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
    protected:
        static int s_count;
        static Animal* s_ptr;
        int m_age;
        double m_weight;
    public:
        Animal();
        Animal(int, double);
        Animal(const Animal&);
        static int getCount();
        void print() const;
        virtual void voice() const = 0;
        static void deleteObj();
        virtual ~Animal();
};

#endif //ANIMAL_H