#pragma once
#include "Arduino.h"

class Timer {
public:
    Timer();
    void setup();
    static void irqTimerOverflow();
    int getOverflow(); 
    void saveLastOverflow();
    int  getLastOverflow(); 
   // void resetOverflow();
   
private: //methods
    void addOverflow();

private:
   int m_overflows;
   int m_lastoverflows;
   static Timer *s_timers;
   static int s_nrOfTimers;
};