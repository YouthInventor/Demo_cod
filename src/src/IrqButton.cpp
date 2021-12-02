#include "IrqButton.h"
#include "Arduino.h"

void IrqButton :: setup(int pin,void (*buttonPressedCb)())
    { 
     m_irqButtonPressedCb=buttonPressedCb;
    pinMode (pin, INPUT_PULLUP);
    attachInterrupt (digitalPinToInterrupt(pin),m_irqButtonPressedCb,FALLING);
    }  
   
/*static void IrqButton :: switchPressed ()
    { ledStatus = !ledStatus; }  // end of switchPressed  

 bool IrqButton:: result() 
    { return ledStatus;  } 
   bla bla bla
*/