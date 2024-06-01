#include "Amphibian.h"

Amphibian::Amphibian() : Animal() , Terrestrial() , Aquatic()
{
    
} 

Amphibian::Amphibian(double weight , int height , int age, std::string color , std::string climate, double temp) :
                    Animal(weight , height , age, color) , Terrestrial(weight , height , age, color , climate) , 
                    Aquatic(weight , height , age, color , temp)
{
    
}

void Amphibian::print() const
{
    Terrestrial::print();
    std::cout << "Temperature : " << m_temp << std::endl;
}

Amphibian::~Amphibian()
{
    
}