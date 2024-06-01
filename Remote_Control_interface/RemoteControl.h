#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include <iostream>
#include <string>
#include "IRemoteControl.h"

class RemoteControl : public IRemoteControl
{
    private:
        bool m_isOn;
        int m_channel;
        int m_volume;
    public:
        RemoteControl();
        void turnOff() override;
        void turnOn() override;
        void pressButton(int) override;
        void goRight() override;
        void goLeft() override;
        void turnUpVol() override;
        void turnDownVol() override;
        int getChannel() const override;
        int getVol() const override;
        void printInfo() const override;
        ~RemoteControl();
};

#endif // REMOTECONTROL_H