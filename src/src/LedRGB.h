
#include "fonts/FastLED/src/FastLED.h" 
#include "Menu.h"

class LedRGB{
public:
    LedRGB();
    void lightLed(Menu &menu);
    void turnOff();

private:
    CRGB leds[4];
    void turnOn();
    
    void flashWhite();
    void flashGreen();
    void flashRed();
    void flashBG();
    int m_pin;
    int m_numLeds;
    //static Timer *s_timers[3];
};