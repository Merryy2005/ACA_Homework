#ifndef IREMOTECONTROL_H
#define IREMOTECONTROL_H

class IRemoteControl
{
    public:
        virtual void turnOff() = 0;
        virtual void turnOn() = 0;
        virtual void pressButton(int) = 0;
        virtual void goRight() = 0;
        virtual void goLeft() = 0;
        virtual void turnUpVol() = 0;
        virtual void turnDownVol() = 0;
        virtual int getChannel() const = 0;
        virtual int getVol() const = 0;
        virtual void printInfo() const = 0;
        virtual ~IRemoteControl(){};
};

#endif // IREMOTECONTROL_H