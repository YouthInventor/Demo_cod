#include "Timer.h"

//Timer *Timer::s_timers[3];
//int Timer::s_nrOfTimers = 0;

Timer *Timer::s_timers;

ISR(TIMER1_OVF_vect)
{ 
Timer::irqTimerOverflow();
}

Timer::Timer() {
   s_timers= this;
  //  s_nrOfTimers += 1;
   
}

void Timer:: setup()
{ m_overflows = 0; 
  m_lastoverflows = 0;
  noInterrupts(); 
  TCCR1A = 0; TCCR1B = 0; //reset Timer 1 control registers
  TCNT1 = 0;              //reset Timer 1 counter register
  TCCR1B |= 0b11000101;   //1024 prescaler, rising edge, noise canceler
  TIMSK1 |= 0b00100001;   //enable input capture & overflow interrupts
  interrupts();
}
void Timer::irqTimerOverflow() {
  s_timers->addOverflow();
}

void Timer::addOverflow() {
  //  if (m_isRunning)
    m_overflows++;
}

void Timer::saveLastOverflow()
{ m_lastoverflows = m_overflows; }

int Timer::getLastOverflow()
{ return s_timers->m_lastoverflows; }

int Timer::getOverflow() 
{ return s_timers->m_overflows; }

/*
void Timer::start() {
    m_overflows = 0;
    int TCNT1 = 13; // TODO should be from the library!, REMOVE THIS LINE
    m_startTime = TCNT1;
}

int Timer::stop() {
    m_isRunning = false;
    int TCNT1 = 0; // TODO, fix this
    m_stopTime = TCNT1;
    return getTime();
}

int Timer::getTime() {
    int TCNT1 = 0; // TODO fix this
    int currentTime = TCNT1;
    if (!m_isRunning) currentTime = m_stopTime;
    
    int diff = 0; // Calculate time with startTime, m_overflows and current TCNT1
    return diff;
}

*/