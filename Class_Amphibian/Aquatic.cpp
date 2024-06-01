#include "Aquatic.h"

Aquatic::Aquatic() : Animal() , m_temp(0.0)
{
    
}

Aquatic::Aquatic(double weight , int height , int age, std::string color , double temp) : 
                Animal(weight , height , age , color) , m_temp(temp)
{
    
}

void Aquatic::print() const
{
    Animal::print();
    std::cout << "Temperature : " << m_temp << std::endl; 
}

Aquatic::~Aquatic()
{
      
}