#pragma once

class IrqButton
  { 
 public:
   void setup(int pin,void (*buttonPressedCb)()); // address of static func

 private: 
    void (*m_irqButtonPressedCb)();  
  };  
  