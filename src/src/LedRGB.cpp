#include "LedRGB.h"
#include "Arduino.h"

 LedRGB :: LedRGB()
{ 
 // m_pin=13;
 // m_numLeds=4;
  FastLED.addLeds<WS2813, 13, GRB>(leds, 4);  //pin 13 numLeds=4
  FastLED.setBrightness(100);
 }


void LedRGB :: turnOn()
{
  for (int i=0;i<4;i++)
   {
   // Засветваме светодиодите един по един 
   leds[i]= CRGB::Yellow;
   FastLED.show();
   } 

}


void LedRGB :: turnOff()
{
  for(int i=0;i<4;i++)
   {
   // Изгасяме светодиодите по обратният ред
   leds[i] = CRGB::Black;
   FastLED.show();
   } 
}

void LedRGB::lightLed(Menu &menu) //first page
{ 
  if(menu.currentPage()==Page::StopWatch) 
 { switch (menu.currentColor())
   { case 0:  flashWhite(); 
       break; 
     case 1:  flashGreen();
       break;
     case 2: flashRed();
       break;
     case 3: flashBG();
       break; 
     
    } 
  } else this->turnOff(); 

}

void LedRGB :: flashWhite()
{
  for(int i=0;i<4;i++)
   {leds[i] = CRGB::White;
    FastLED.show();
   } 
}


void LedRGB :: flashGreen()
{
  for(int i=0;i<4;i++)
   { leds[i] = CRGB::Green;
     FastLED.show();
   } 
}


void LedRGB :: flashRed()
{
  for(int i=0;i<4;i++)
   { leds[i] = CRGB::Red;
     FastLED.show();
   } 
}

void LedRGB :: flashBG()
{
   leds[0] = CRGB::White;
   leds[1] = CRGB::Green;
   leds[2] = CRGB::Red;
   leds[3] = CRGB::Black;
   FastLED.show();  
}
