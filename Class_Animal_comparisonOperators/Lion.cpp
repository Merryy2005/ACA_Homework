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

Lion::Lion(Lion&& other) : Animal(std::move(other))
{
    
}

Lion& Lion::operator= (const Lion& other)
{
    if(this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}

Lion& Lion::operator= (Lion&& other)
{
    if(this != &other)
    {
        Animal::operator=(std::move(other));
    }
    return *this;
}

void Lion::voice() const
{
    std::cout << "I'm a Lion" << std::endl;
}

std::string Lion::name() const
{
    return "Lion";
}

Lion::~Lion()
{
    
}