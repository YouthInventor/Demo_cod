#pragma once

#include "Button.h"
#include "Led.h"
#include "Menu.h"
#include "UI.h"
#include "LedRGB.h"
#include "Distance.h"
#include "IR.h"
#include "Timer.h"

class App {

private:  
  static App *s_app;
  Menu m_menu;
  Button m_buttons[3]; 
  Led  m_led;
  UI   m_ui;
  LedRGB m_rgb;
  Distance m_distance;
  IR m_ir;
  Timer m_timer;

private: //methods
 static void previousButtonPushed();
 static void nextButtonPushed();
 static void selectButtonPressed();
 
 static void sleepNow();
 static void wakeUp();
public:
  App();
  void setup();
  void loop();
};