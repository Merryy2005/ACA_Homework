#include <iostream>
#include <string>

class Car{
    private:
        std::string m_model;
        std::string m_brand;
        std::string m_color;
        int m_speed;
        int m_year;
        std::string m_engineType;
    public:
        Car() : m_speed(0) , m_year(0)
        {

        };

        Car(std::string model , std::string brand , std::string color , int speed , 
            int year , std::string engineType) :
            m_model(model) , m_brand(brand) , m_color(color) , m_speed(speed) , 
            m_year(year) , m_engineType(engineType)
        {

        };

        Car(const Car& other) : 
            m_model(other.m_model) , m_brand(other.m_brand) , m_color(other.m_color) , m_speed(other.m_speed) , 
            m_year(other.m_year) , m_engineType(other.m_engineType)
        {

        };

        void printCar() const
        {
            std::cout << "Car : " << m_model << " " << m_brand << std::endl;
            std::cout << "Color : " << m_color << std::endl;
            std::cout << "Speed : " << m_speed << "km/h" << std::endl;
            std::cout << "Release year : " << m_year << std::endl;
            std::cout << "Engine type : " << m_engineType << std::endl;
        };

        ~Car()
        {

        };
};

//honda toyota mercedes

class Honda : public Car{
    private:
        bool m_cruiseControl;
    public:
        Honda() : Car() , m_cruiseControl(false)
        {

        };

        Honda(std::string brand , std::string color , int speed , 
              int year , std::string engineType , bool cruiseControl) : 
             Car("Honda" , brand , color , speed , year , engineType) , m_cruiseControl(cruiseControl)
        {

        };

        Honda(const Honda& other) :
             Car(other) , m_cruiseControl(other.m_cruiseControl)
        {
            
        };

        void printHonda() const
        {
            printCar();
            std::cout << (m_cruiseControl ? "Has cruise control" : "Doesn't have cruise control") << std::endl;
        };

        ~Honda()
        {

        };
};

class Toyota : public Car{
    private:
        bool m_safetySystem;
    public:
        Toyota() : Car() , m_safetySystem(false)
        {

        };

        Toyota(std::string brand , std::string color , int speed , 
              int year , std::string engineType , bool safetySystem) : 
             Car("Toyota" , brand , color , speed , year , engineType) , m_safetySystem(safetySystem)
        {

        };

        Toyota(const Toyota& other) :
            Car(other) , m_safetySystem(other.m_safetySystem)
        {

        };

        void printToyota() const
        {
            printCar();
            std::cout << (m_safetySystem ? "Has safety system" : "Doesn't have safety system") << std::endl;
        };

        ~Toyota()
        {

        };
};

class Mercedes : public Car{
    private:
        bool m_kneeAirbags;
    public:
        Mercedes() : Car() , m_kneeAirbags(false)
        {

        };

        Mercedes(std::string brand , std::string color , int speed , 
              int year , std::string engineType , bool kneeAirbags) : 
             Car("Mercedes" , brand , color , speed , year , engineType) , m_kneeAirbags(kneeAirbags)
        {

        };

        Mercedes(const Mercedes& other) :
                Car(other) , m_kneeAirbags(other.m_kneeAirbags)
        {

        };

        void printMercedes() const
        {
            printCar();
            std::cout << (m_kneeAirbags ? "Has knee airbags" : "Doesn't have knee airbags") << std::endl;
        };

        ~Mercedes()
        {

        };
};

class HondaEns1 : public Honda{
    private:
        bool m_cmbs;
        int m_power;
    public:
        HondaEns1() : Honda() , m_cmbs(false) , m_power(0)
        {

        };

        HondaEns1(std::string color , int speed , 
                  int year , bool cruiseControl , bool cmbs , int power) :
                  Honda("Ens1" , color , speed , year , "Electric" , cruiseControl) , m_cmbs(cmbs) , m_power(power)
        {

        };

        HondaEns1(const HondaEns1& other) :
                 Honda(other) , m_cmbs(other.m_cmbs) , m_power(other.m_power)
        {

        };

        void printHondaEns1() const
        {
            printHonda();
            std::cout << (m_cmbs ? "Has collision mitigation mraking mystem" : "Doesn't have collision mitigation braking system") << std::endl;
            std::cout << "Motor maximum power : " << m_power << "kW" << std::endl;
        };  

        ~HondaEns1()
        {

        };

};

class ToyotaCamry : public Toyota{
    private:
        bool m_hybridDrivetrain;
    public:
        ToyotaCamry() : Toyota() ,  m_hybridDrivetrain(false)
        {

        };

        ToyotaCamry(std::string color , int speed , int year , 
                    bool safetySystem , bool hybridDrivetrain) : 
                    Toyota("Camry" ,color , speed , year , "Petrol" , safetySystem) , m_hybridDrivetrain(hybridDrivetrain)
        {

        };

        ToyotaCamry(const ToyotaCamry& other) :
                    Toyota(other) , m_hybridDrivetrain(other.m_hybridDrivetrain)
        {

        };  

        void printToyotaCamry() const
        {
            printToyota();
            std::cout << (m_hybridDrivetrain ? "Has hybrid drivetrain" : "Doesn't have hybrid drivetrain") << std::endl;
        };

        ~ToyotaCamry()
        {

        };
};

class MercedesAMG : public Mercedes{
    private:
        bool m_performanceExhaust;
    public:
        MercedesAMG() : Mercedes() , m_performanceExhaust(false)
        {

        };

        MercedesAMG(std::string color , int speed , int year , 
                    bool kneeAirbags, bool navigationSystem, bool performanceExhaust) : 
             Mercedes("AMG" , color , speed , year , "Petrol" , kneeAirbags) , m_performanceExhaust(performanceExhaust)
        {

        };

        MercedesAMG(const MercedesAMG& other) : 
                    Mercedes(other) , m_performanceExhaust(other.m_performanceExhaust)
        {

        };

        void printMercedesAMG() const
        {
            printMercedes();
            std::cout << (m_performanceExhaust ? "Has performance exhaust" : "Doesn't have performance exhaust") << std::endl;
        };

        ~MercedesAMG()
        {

        };
};

int main()
{
    HondaEns1 myCar1("White" , 150 , 2023 , true , true , 140);
    myCar1.printHondaEns1();
    std::cout << "______________" << std::endl;
    ToyotaCamry myCar2("Black", 180, 2024, true, false);
    myCar2.printToyotaCamry();
    std::cout << "______________" << std::endl;
    MercedesAMG myCar3("Silver", 300, 2024, true, true, true);
    myCar3.printMercedesAMG();
    std::cout << "______________" << std::endl;
    MercedesAMG myCar4(myCar3);
    myCar4.printMercedesAMG();
    return 0;
}