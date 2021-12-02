#include "Distance.h"
#include "Arduino.h"

Distance :: Distance()
{  m_echoPin=12;
   m_trigerPin=6;
  pinMode(m_trigerPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(m_echoPin, INPUT); // Sets the echoPin as an Input
}

int Distance :: measure()
{ long duration; // variable for the duration of sound wave travel
  digitalWrite(m_trigerPin, LOW);
  delayMicroseconds(2);  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(m_trigerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(m_trigerPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(m_echoPin, HIGH);
  
  // Calculating the distance
   return duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
 
}
