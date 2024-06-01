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
    animals[0] = Bear::createObj(1 , 10);
    animals[1] = Elephant::createObj(3 , 105.5);
    animals[2] = Giraffe::createObj(6 , 70);
    animals[3] = Lion::createObj(5 , 100.7);
    animals[4] = Tiger::createObj(8 , 101.1);
    //all are the same Bear
    for(int i = 0 ; i < 5 ; i++)
    {
        animals[i]->print();
        std::cout << "-----------" << std::endl;
    }
    std::cout << "Number of Animals : "<< Animal::getCount() << std::endl; // only 1
    for(int i = 0 ; i < 5 ; i++)
    {
        animals[i] -> deleteObj();
        animals[i] = nullptr;
    }
    delete[] animals;
    animals = nullptr;
    return 0;
}
