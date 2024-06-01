#include "Animal.h"

int Animal::s_count = 0;
Animal* Animal::s_ptr = nullptr;

Animal::Animal() : m_age(0) , m_weight(0)
{
    Animal::s_count++;
}

Animal::Animal(int age , double weight) : m_age(age) , m_weight(weight)
{
    Animal::s_count++;
}

Animal::Animal(const Animal& other) : m_age(other.m_age) , m_weight(other.m_weight)
{
    Animal::s_count++;
}

int Animal::getCount()
{
    return s_count;
}

void Animal::print() const
{
    voice();
    std::cout << "Age : " << m_age << std::endl;
    std::cout << "Weight : " << m_weight << std::endl;
}

Animal::~Animal()
{
    Animal::s_count--;   
}