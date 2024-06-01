#include "Elephant.h"

Elephant::Elephant(int age , double weight) : Animal(age , weight)
{

}

void Elephant::voice() const
{
    std::cout << "I'm a Elephant" << std::endl;
}

Animal* Elephant::createObj(int age, double weight)
{
    if(Animal::s_ptr == nullptr)
    {
        Animal::s_ptr = new Elephant(age , weight);
    }
    return Animal::s_ptr;
}

Elephant::~Elephant()
{
    
}