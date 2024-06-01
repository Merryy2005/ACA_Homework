#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
    static int s_count;
    protected:
        int m_age;
        double m_weight;
    public:
        Animal();
        Animal(int, double);
        Animal(const Animal&);
        Animal(Animal&&);
        virtual Animal& operator= (const Animal&);
        virtual Animal& operator= (Animal&&);
        static int getCount();
        void print() const;
        virtual void voice() const = 0;
        virtual std::string name() const = 0;
        virtual ~Animal();
};

#endif //ANIMAL_H