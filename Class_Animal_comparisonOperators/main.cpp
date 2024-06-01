#include <iostream>
#include "Animal.h"
#include "Bear.h"
#include "Elephant.h"
#include "Giraffe.h"
#include "Lion.h"
#include "Tiger.h"


int main()
{
    Animal** animals = new Animal*[8];
    animals[0] = new Bear(1 , 10);
    animals[1] = new Elephant(3 , 105.5);
    animals[2] = new Giraffe(6 , 70);
    animals[3] = new Lion(6 , 110);
    animals[4]= new Tiger(8 , 101.1);
    animals[5] = new Giraffe(4 , 90.7);
    animals[6] = new Lion(3 , 106);
    animals[7]= new Tiger(10 , 99.8);
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = i+1 ; j < 8 ; j++)
        {
            if(*animals[i] < *animals[j])
            {
                Animal* temp = animals[i];
                animals[i] = animals[j];
                animals[j] = temp;
            }
        }
    }
    for(int i = 0 ; i < 3 ; i++)
    {
        animals[i] -> print();
        std::cout << "-----------" << std::endl;
    }
    for(int i = 0 ; i < 8 ; i++)
    {
        delete animals[i];
        animals[i] = nullptr;
    }
    delete[] animals;
    animals = nullptr;
    return 0;
}
