#include "Giraffe.h"

Giraffe::Giraffe() : Animal()
{

}

Giraffe::Giraffe(int age , double weight) : Animal(age , weight)
{

}

Giraffe::Giraffe(const Giraffe& other) : Animal(other)
{

}

Giraffe::Giraffe(Giraffe&& other) : Animal(std::move(other))
{
    
}

Giraffe& Giraffe::operator= (const Giraffe& other)
{
    if(this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}

Giraffe& Giraffe::operator= (Giraffe&& other)
{
    if(this != &other)
    {
        Animal::operator=(std::move(other));
    }
    return *this;
}

void Giraffe::voice() const
{
    std::cout << "I'm a Giraffe" << std::endl;
}

std::string Giraffe::name() const
{
    return "Giraffe";
}


Giraffe::~Giraffe()
{
    
}