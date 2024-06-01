#include <iostream>
#include "Animal.h"
#include "Bear.h"
#include "Elephant.h"
#include "Giraffe.h"
#include "Lion.h"
#include "Tiger.h"


int main()
{
    Bear b(std::move(Bear(3, 5)));
    Elephant e;
    e = Elephant(4 , 5);
    Animal *b1 = new Bear(3,5);
    Animal *b2 = new Bear(4,7);
    *b1 = *b2;
    b1->print();
    return 0;
}
