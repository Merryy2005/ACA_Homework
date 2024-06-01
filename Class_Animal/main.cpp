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
    animals[0] = new Bear();
    animals[1] = new Elephant();
    animals[2] = new Giraffe();
    animals[3] = new Lion();
    animals[4]= new Tiger();
    for(int i = 0 ; i < 5 ; i++)
    {
        animals[i]->voice();
    }
    for(int i = 0 ; i < 5 ; i++)
    {
        delete animals[i];
        animals[i] = nullptr;
    }
    delete[] animals;
    animals = nullptr;
    return 0;
}