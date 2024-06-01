#ifndef ICAR_H
#define ICAR_H

#include <string>

class ICar
{
    public:
        virtual std::string getSignal() const = 0;
        virtual void startEngine() const = 0;
        virtual void stopEngine() const = 0;
        virtual bool isAutomatic() const = 0;
        virtual bool isElectric() const = 0;
        virtual std::string getModel() const = 0;
        virtual std::string getBrand() const = 0;
        virtual std::string getColor() const = 0;
        virtual int getSpeed() const = 0;
        virtual int getYear() const = 0;
        virtual int getHorsePower() const = 0;
        virtual std::string getEngineType() const = 0;
        virtual void printCar() const = 0;
        virtual ~ICar(){};
};

#endif //ICAR_H