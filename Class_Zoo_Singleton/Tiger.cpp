#include "Tiger.h"

Tiger::Tiger(int age , double weight) : Animal(age , weight)
{

}

void Tiger::voice() const
{
    std::cout << "I'm a Tiger" << std::endl;
}

Animal* Tiger::createObj(int age, double weight)
{
    if(Animal::s_ptr == nullptr)
    {
        Animal::s_ptr = new Tiger(age , weight);
    }
    return Animal::s_ptr;
}

Tiger::~Tiger()
{
    
}