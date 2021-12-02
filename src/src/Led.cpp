#include "Led.h"
#include "Arduino.h"

void Led :: setup(int pin)
{  m_pin=pin;
   pinMode(m_pin,OUTPUT);  
}

void Led :: turnOn()
{
  digitalWrite(m_pin, HIGH);
  m_status=1;
}

void Led :: turnOff()
{
  digitalWrite(m_pin, LOW);
  m_status=0;
}
