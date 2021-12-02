#pragma once

class Led{
public:
   // Led();
    void setup(int pin);
    void turnOn();
    void turnOff();

private:
    int m_status;
    int m_pin;
    //static Timer *s_timers[3];
};