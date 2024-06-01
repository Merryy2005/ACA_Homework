#include <iostream>
#include "Animal.h"
#include "Bear.h"
#include "Elephant.h"
#include "Giraffe.h"
#include "Lion.h"
#include "Tiger.h"

int main()
{
    Animal** animals = new Animal*[5];
    animals[0] = new Bear(1 , 10);
    animals[1] = new Elephant(3 , 105.5);
    animals[2] = new Giraffe(6 , 70);
    std::cout << "Number of Animals : "<< Animal::getCount() << std::endl;
    animals[3] = new Lion(5 , 100.7);
    animals[4]= new Tiger(8 , 101.1);
    Bear b(*((Bear*)animals[0]));
    for(int i = 0 ; i < 5 ; i++)
    {
        animals[i]->print();
        std::cout << "-----------" << std::endl;
    }
    std::cout << "Number of Animals : "<< Animal::getCount() << std::endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        delete animals[i];
        animals[i] = nullptr;
    }
    delete[] animals;
    animals = nullptr;
    std::cout << "Number of Animals : "<< Animal::getCount() << std::endl;
    return 0;
}
