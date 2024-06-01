#include "Animal.h"
#include "Terrestrial.h"
#include "Aquatic.h"
#include "Amphibian.h"

int main()
{
    Amphibian a(10.5, 20, 5, "Green", "Tropical", 25.0);
    a.print();
    return 0;
}