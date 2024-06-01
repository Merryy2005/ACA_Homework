#include "Bear.h"

Bear::Bear() : Animal()
{

}

Bear::Bear(int age , double weight) : Animal(age , weight)
{

}

Bear::Bear(const Bear& other) : Animal(other)
{

}

Bear::Bear(Bear&& other) : Animal(std::move(other))
{
    
}

Bear& Bear::operator= (const Bear& other)
{
    if(this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}

Bear& Bear::operator= (Bear&& other)
{
    if(this != &other)
    {
        Animal::operator=(std::move(other));
    }
    return *this;
}

void Bear::voice() const
{
    std::cout << "I'm a Bear" << std::endl;
}

std::string Bear::name() const
{
    return "Bear";
}

Bear::~Bear()
{
    
}