#include "RemoteControl.h"

int main()
{
    RemoteControl pult;
    pult.turnUpVol();
    pult.goRight();
    pult.printInfo();
    pult.turnOff();
    pult.printInfo();
    return 0;
}