#include "Honda.h"

Honda::Honda() : Car() , m_cruiseControl(false)
{

}

Honda::Honda(std::string brand , std::string color , int speed , 
            int year , int horsePower , std::string engineType , bool cruiseControl) : 
            Car("Honda" , brand , color , speed , year , horsePower , engineType) , m_cruiseControl(cruiseControl)
{

}

Honda::Honda(const Honda& other) :
             Car(other) , m_cruiseControl(other.m_cruiseControl)
{
            
}

std::string Honda::getSignal() const
{
    return "Honda signal";
}

void Honda::startEngine() const
{
    std::cout << "Honda start" << std::endl;
}

void Honda::stopEngine() const
{
    std::cout << "Honda stop" << std::endl;
}

bool Honda::isAutomatic() const
{
    return true;
}

bool Honda::isElectric() const
{
    return true;
}

void Honda::printCar() const
{
    std::cout << "Car : " << "Honda" << " " << m_brand << std::endl;
    std::cout << "Color : " << m_color << std::endl;
    std::cout << "Speed : " << m_speed << "km/h" << std::endl;
    std::cout << "Release year : " << m_year << std::endl;
    std::cout << "HorsePower : " << m_horsePower << std::endl;
    std::cout << "Engine type : " << m_engineType << std::endl;
    std::cout << (m_cruiseControl ? "Has cruise control" : "Doesn't have cruise control") << std::endl;
}

Honda::~Honda()
{

}