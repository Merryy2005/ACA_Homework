#include "Animal.h"

Animal::Animal() : m_weight(0.0) , m_height(0) , m_age(0) , m_color("")
{

}

Animal::Animal(double weight , int height , int age, std::string color) : 
                m_weight(weight) , m_height(height) , m_age(age) , m_color(color)
{
     
}

void Animal::print() const
{
    std::cout << "Weight : " << m_weight << std::endl;
    std::cout << "Height : " << m_height << std::endl;
    std::cout << "Age : " << m_age << std::endl;
    std::cout << "Color : " << m_color << std::endl;
}

Animal::~Animal()
{
    
}