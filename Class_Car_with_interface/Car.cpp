#include "Car.h"

Car::Car() : m_speed(0) , m_year(0) , m_horsePower(0)
{

}

Car::Car(std::string model , std::string brand , std::string color , int speed , int year , 
        int horsePower , std::string engineType) :
        m_model(model) , m_brand(brand) , m_color(color) , m_speed(speed) , m_year(year) , 
        m_horsePower(horsePower) , m_engineType(engineType)
{

}

Car::Car(const Car& other) : 
        m_model(other.m_model) , m_brand(other.m_brand) , m_color(other.m_color) , m_speed(other.m_speed) , 
        m_year(other.m_year) , m_horsePower(other.m_horsePower) , m_engineType(other.m_engineType)
{

}

std::string Car::getModel() const
{
    return m_model;
}

std::string Car::getBrand() const
{
    return m_brand;
}

std::string Car::getColor() const
{
    return m_color;
}

int Car::getSpeed() const
{
    return m_speed;
}

int Car::getYear() const
{
    return m_year;
}

int Car::getHorsePower() const
{
    return m_horsePower;
}

std::string Car::getEngineType() const
{
    return m_engineType;
}

Car::~Car()
{

}