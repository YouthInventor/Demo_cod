#include "Button.h"
#include "Arduino.h"

void Button::setup(int pin,void (*buttonPressedCb)()) 
{  m_pin=pin;
   m_buttonPressedCb=buttonPressedCb;
   pinMode(m_pin, INPUT_PULLUP);
 
}

void Button::loop() { 
    if (digitalRead(m_pin) == LOW) 
    { 
        m_buttonPressedCb(); 
        delay(200); // fix debounce
    /*
      long currentTime=millis(); 
      if(currentTime - m_lastPressedTime>180)
       { m_lastPressedTime=currentTime;
         m_buttonPressedCb(); 
       }       
       */
    }
}