#include <iostream>
#include <string>

class Car{
    private:
        std::string mark = "Honda";
        std::string color = "White";
        std::string regnumber = "00AA000";
        std::string prodplace = "China";
        int horsepower = 204;
        int doors = 4;
        int maxspeed = 150;
    public:
        void print()
        {
            std::cout << color << " " << mark << std::endl;
            std::cout << "Pethamaranish: " << regnumber << std::endl;
            std::cout << "Production place: "<< prodplace << std::endl;
            std::cout << "Horsepower: "<< horsepower << "HP" << std::endl;
            std::cout << "Number of doors: " << doors << std::endl;
            std::cout << "Maximum speed: " << maxspeed << std::endl;
            return;
        }
};

int main(){
    Car myCar;
    myCar.print();
    return 0;
}