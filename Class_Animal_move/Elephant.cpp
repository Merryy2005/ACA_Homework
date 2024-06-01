#include "Elephant.h"

Elephant::Elephant() : Animal()
{

}

Elephant::Elephant(int age , double weight) : Animal(age , weight)
{

}

Elephant::Elephant(const Elephant& other) : Animal(other)
{

}

Elephant::Elephant(Elephant&& other) : Animal(std::move(other))
{
    
}

Elephant& Elephant::operator= (const Elephant& other)
{
    if(this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}

Elephant& Elephant::operator= (Elephant&& other)
{
    if(this != &other)
    {
        Animal::operator=(std::move(other));
    }
    return *this;
}

void Elephant::voice() const
{
    std::cout << "I'm an Elephant" << std::endl;
}

std::string Elephant::name() const
{
    return "Elephant";
}

Elephant::~Elephant()
{
    
}