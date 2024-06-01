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

Tiger::Tiger(Tiger&& other) : Animal(std::move(other))
{
    
}

Tiger& Tiger::operator= (const Tiger& other)
{
    if(this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}

Tiger& Tiger::operator= (Tiger&& other)
{
    if(this != &other)
    {
        Animal::operator=(std::move(other));
    }
    return *this;
}

void Tiger::voice() const
{
    std::cout << "I'm a Tiger" << std::endl;
}

std::string Tiger::name() const
{
    return "Tiger";
}

Tiger::~Tiger()
{
    
}