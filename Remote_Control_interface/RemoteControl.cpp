#include "RemoteControl.h"

RemoteControl::RemoteControl() : m_isOn(true) , m_channel(1) , m_volume(50)
{

}

void RemoteControl::turnOff()
{
    m_isOn = false;
}

void RemoteControl::turnOn()
{
    m_isOn = true;
}

void RemoteControl::pressButton(int x)
{
    m_channel = x;
}

void RemoteControl::goRight()
{
    m_channel++;
}

void RemoteControl::goLeft()
{
    m_channel--;
}

void RemoteControl::turnUpVol()
{
    m_volume++;
}

void RemoteControl::turnDownVol()
{
    m_volume--;
}

int RemoteControl::getChannel() const
{
    return m_channel;
}

int RemoteControl::getVol() const
{
    return m_volume;
}

void RemoteControl::printInfo() const
{
    std::cout << "Status : " << (m_isOn ? "ON" : "OFF") << std::endl;
    std::cout << "Channel : " << m_channel << std::endl;
    std::cout << "Volume : " << m_volume << std::endl;
}
RemoteControl::~RemoteControl()
{

}