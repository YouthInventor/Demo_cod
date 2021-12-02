#pragma once

class Led{
public:
    void setup(int pin);
    void turnOn();
    void turnOff();

private:
    int m_status;
    int m_pin;
};