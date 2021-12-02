#pragma once

class Button{
public:
    void setup(int pin,void (*buttonPressedCb)());
    void loop();

private:
    int m_pin;
    int m_lastPressedTime; // set this to currentTime() when button is pressed
    void (*m_buttonPressedCb)();
};