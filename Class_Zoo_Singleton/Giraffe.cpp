#include "Giraffe.h"

Giraffe::Giraffe(int age , double weight) : Animal(age , weight)
{

}

void Giraffe::voice() const
{
    std::cout << "I'm a Giraffe" << std::endl;
}

Animal* Giraffe::createObj(int age, double weight)
{
    if(Animal::s_ptr == nullptr)
    {
        Animal::s_ptr = new Giraffe(age , weight);
    }
    return Animal::s_ptr;
}

Giraffe::~Giraffe()
{
    
}