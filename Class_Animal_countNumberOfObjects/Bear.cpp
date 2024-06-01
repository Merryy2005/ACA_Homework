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

void Bear::voice() const
{
    std::cout << "I'm a Bear" << std::endl;
}

Bear::~Bear()
{
    
}