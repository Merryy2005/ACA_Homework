#include "Terrestrial.h"

Terrestrial::Terrestrial() : Animal() , m_climate("")
{

}

Terrestrial::Terrestrial(double weight , int height , int age, std::string color , std::string climate) : 
                Animal(weight , height , age , color) , m_climate(climate)
{
     
}

void Terrestrial::print() const
{
    Animal::print();
    std::cout << "Climate : " << m_climate << std::endl; 
}

Terrestrial::~Terrestrial()
{
    
}