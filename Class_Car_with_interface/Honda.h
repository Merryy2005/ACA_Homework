#ifndef HONDA_H
#define HONDA_H

#include <iostream>
#include "Car.h"

class Honda : public Car
{
    private:
        bool m_cruiseControl;
    public:
        Honda();
        Honda(std::string , std::string , int , int , int , std::string , bool); 
        Honda(const Honda&);
        std::string getSignal() const override;
        void startEngine() const override;
        void stopEngine() const override;
        bool isAutomatic() const override;
        bool isElectric() const override;
        void printCar() const override;
        ~Honda();
};

#endif // HONDA_H