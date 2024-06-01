#include "Lion.h"


Lion::Lion() : Animal()
{

}

Lion::Lion(int age , double weight) : Animal(age , weight)
{

}

Lion::Lion(const Lion& other) : Animal(other)
{

}

void Lion::voice() const
{
    std::cout << "I'm a Lion" << std::endl;
}

Lion::~Lion()
{
    
}