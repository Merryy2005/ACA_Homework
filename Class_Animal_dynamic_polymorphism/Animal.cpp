#include "Animal.h"

Animal::Animal() : m_age(0) , m_weight(0)
{

}

Animal::Animal(int age , double weight) : m_age(age) , m_weight(weight)
{

}

Animal::Animal(const Animal& other) : m_age(other.m_age) , m_weight(other.m_weight)
{

}

void Animal::print() const
{
    voice();
    std::cout << "Age : " << m_age << std::endl;
    std::cout << "Weight : " << m_weight << std::endl;
}

Animal::~Animal()
{
    
}