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

void Giraffe::voice() const
{
    std::cout << "I'm a Giraffe" << std::endl;
}

Giraffe::~Giraffe()
{
    
}