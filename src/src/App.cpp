#include "App.h"
#include "Arduino.h"
#include <avr/sleep.h> 
#include <avr/power.h>

App *App::s_app = nullptr;

App::App()
 {   s_app = this; }

void App::setup() {
    Serial.begin(9600);
    m_buttons[0].setup(14,&previousButtonPushed);
    m_buttons[1].setup(15,&nextButtonPushed);
    m_buttons[2].setup(2,&selectButtonPressed);
    m_led.setup(13);
    m_menu.setup();
    m_timer.setup();
  //  s_app->m_ui.drawIntro();
    s_app->m_ui.draw(s_app->m_menu);
  
}

void App::loop() {
    for(int i = 0; i < 3; i++) m_buttons[i].loop();
    if(static_cast<int>(s_app->m_menu.currentPage()) == 2) 
     { s_app->m_ui.draw(s_app->m_menu,s_app->m_distance.measure()); }
     else if(static_cast<int>(s_app->m_menu.currentPage()) == 3) 
      { 
    // if(s_app->m_ir.decode()!='e') s_app->m_ui.draw(s_app->m_menu,s_app->m_ir.decode());
        }  
  Serial.print("Ovf=");
  Serial.println(s_app->m_timer.getOverflow());
  Serial.print("Last=");
  Serial.println(s_app->m_timer.getLastOverflow());

  if((s_app->m_timer.getOverflow()-s_app->m_timer.getLastOverflow())>4) // approximately 15 sec
    { if(static_cast<int>(s_app->m_menu.currentPage()) == 1) { s_app->m_rgb.turnOff(); } //turn off lights
      s_app->sleepNow();  
     } 
}

// Static methods, no access to object members except through s_app pointer
static void App::previousButtonPushed() {
  //Serial.println("prev");
  s_app->m_menu.previous();
  s_app->m_ui.draw(s_app->m_menu);
  s_app->m_rgb.lightLed(s_app->m_menu);
  s_app->m_timer.saveLastOverflow();
}

static void App::nextButtonPushed() {
 //  Serial.println("next");
   s_app->m_menu.next();
   s_app->m_ui.draw(s_app->m_menu);
   s_app->m_rgb.lightLed(s_app->m_menu);
   s_app->m_timer.saveLastOverflow();
}

static void App::selectButtonPressed() {
// Serial.println("select");
   s_app->m_menu.select();
   s_app->m_ui.draw(s_app->m_menu);
   s_app->m_rgb.lightLed(s_app->m_menu);
   s_app->m_timer.saveLastOverflow();
} 


static void App::sleepNow() 
{
  s_app->m_ui.sleep(); //u8g.sleepOn();
  delay(150);
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);   
  noInterrupts ();          // make sure we don't get interrupted before we sleep
  sleep_enable ();          // enables the sleep bit in the mcucr register
  attachInterrupt (digitalPinToInterrupt (2), s_app->wakeUp, LOW);  // wake up on low level on D2
  interrupts ();           // interrupts allowed now, next instruction WILL be executed
  sleep_cpu ();  
}

static void App::wakeUp() 
{ 
  sleep_disable ();         // first thing after waking from sleep:
  detachInterrupt (digitalPinToInterrupt (2));  // stop LOW interrupt on D2
  s_app->m_ui.wake();
  if(static_cast<int>(s_app->m_menu.currentPage()) == 1) {  s_app->m_rgb.lightLed(s_app->m_menu); } 
  delay(150);
  s_app->m_timer.saveLastOverflow();
}