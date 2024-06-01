#include "Lion.h"

Lion::Lion(int age , double weight) : Animal(age , weight)
{

}

void Lion::voice() const
{
    std::cout << "I'm a Lion" << std::endl;
}

Animal* Lion::createObj(int age, double weight)
{
    if(Animal::s_ptr == nullptr)
    {
        Animal::s_ptr = new Lion(age , weight);
    }
    return Animal::s_ptr;
}

Lion::~Lion()
{
    
}