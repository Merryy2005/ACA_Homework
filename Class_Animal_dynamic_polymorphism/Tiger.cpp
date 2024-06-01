#include "Tiger.h"

Tiger::Tiger() : Animal()
{

}

Tiger::Tiger(int age , double weight) : Animal(age , weight)
{

}

Tiger::Tiger(const Tiger& other) : Animal(other)
{

}

void Tiger::voice() const
{
    std::cout << "I'm a Tiger" << std::endl;
}

Tiger::~Tiger()
{
    
}