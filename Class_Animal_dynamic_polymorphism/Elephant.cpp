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

void Elephant::voice() const
{
    std::cout << "I'm an Elephant" << std::endl;
}

Elephant::~Elephant()
{
    
}