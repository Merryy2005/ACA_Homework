#ifndef CAR_H
#define CAR_H
#include "ICar.h"

class Car : public ICar
{
    protected:
        std::string m_model;
        std::string m_brand;
        std::string m_color;
        int m_speed;
        int m_year;
        int m_horsePower;
        std::string m_engineType;
    public:
        Car();
        Car(std::string , std::string , std::string , int , int , int , std::string);
        Car(const Car&);
        std::string getModel() const final;
        std::string getBrand() const final;
        std::string getColor() const final;
        int getSpeed() const final;
        int getYear() const final;
        int getHorsePower() const final;
        std::string getEngineType() const final;
        ~Car();
};

#endif //CAR_H