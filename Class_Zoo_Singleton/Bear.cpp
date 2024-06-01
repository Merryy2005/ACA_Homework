#include "Bear.h"

Bear::Bear(int age , double weight) : Animal(age , weight)
{

}

void Bear::voice() const
{
    std::cout << "I'm a Bear" << std::endl;
}

Animal* Bear::createObj(int age, double weight)
{
    if(Animal::s_ptr == nullptr)
    {
        Animal::s_ptr = new Bear(age , weight);
    }
    return Animal::s_ptr;
}

Bear::~Bear()
{
    
}