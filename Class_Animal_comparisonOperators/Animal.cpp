#include "Animal.h"

int Animal::s_count = 0;

Animal::Animal() : m_age(0) , m_weight(0) , m_ptr(nullptr)
{
    Animal::s_count++;
}

Animal::Animal(int age , double weight) : m_age(age) , m_weight(weight) , m_ptr(new int[m_age])
{
    Animal::s_count++;
}

Animal::Animal(const Animal& other) : m_age(other.m_age) , m_weight(other.m_weight)
{
    m_ptr = new int[m_age];
    for(int i = 0 ; i < m_age ; i++)
    {
        m_ptr[i] = other.m_ptr[i];
    }
    Animal::s_count++;
}

Animal::Animal(Animal&& other) : m_age(other.m_age) , m_weight(other.m_weight) , m_ptr(other.m_ptr)
{
    Animal::s_count++;
    other.m_ptr = nullptr;
}

Animal& Animal::operator= (const Animal& other)
{
    if(this != &other)
    {
        if(name() != other.name())
        {
            throw std::runtime_error("Different animals");
        }
        delete[] m_ptr;
        m_age = other.m_age;
        m_weight = other.m_weight;
        m_ptr = new int[m_age];
        for(int i = 0 ; i < m_age ; i++)
        {
            m_ptr[i] = other.m_ptr[i];
        }
    }
    return *this;
}

Animal& Animal::operator= (Animal&& other)
{
    if(this != &other)
    {
        if(name() != other.name())
        {
            throw std::runtime_error("Different animals");
        }
        delete[] m_ptr;
        m_age = other.m_age;
        m_weight = other.m_weight;
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }
    return *this;
}

bool Animal::operator> (const Animal& other)
{
    if(m_age != other.m_age)
    {
        return m_age > other.m_age;
    }
    return m_weight > other.m_weight;
}

bool Animal::operator< (const Animal& other)
{
    if(m_age != other.m_age)
    {
        return m_age < other.m_age;
    }
    return m_weight < other.m_weight;
}

bool Animal::operator== (const Animal& other)
{
    if(m_age == other.m_age && m_weight == other.m_weight)
    {
        return true;
    }
    return false;
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
    delete[] m_ptr;
    m_ptr = nullptr;
    Animal::s_count--;   
}