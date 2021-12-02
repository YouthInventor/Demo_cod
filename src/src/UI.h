#pragma once

#include "Menu.h"
#include "Distance.h"
#include "fonts/U8glib/src/U8glib.h"      // Oled library
#include "fonts/bg7x14B.h"
#include "fonts/U8glib/bg9x18B.h"
#include "fonts/bg5x8.h"
#include "fonts/Icons.h"


class UI {
public:
       UI();
       void drawIntro();
       void draw(Menu &menu);
       void draw(Menu &menu, int s); //take distance as parameter
       void draw(Menu &menu, char* codes); // take IR code as parameter
       void sleep();
       void wake();
private: // methods
    U8GLIB_SSD1306_128X64 *u8g; // oled library obj
   
    void drawOverviewPage(Menu &menu,int battery, bool charge,int temp);
    void drawStopWatchPage(Menu &menu);
    void drawResultsPage(int dis);
    void drawOthersPage(Menu &menu, char* code);
    void printSkier(int skier);  
    void printFooter();  
   // void drawIcons(int bat,bool charge);
};

