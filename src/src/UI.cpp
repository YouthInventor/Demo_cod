#include "UI.h"
#include "Arduino.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define TEXT_WIDTH 7
#define TEXT_HEIGHT 14
#define MENU_ITEMS 3

UI::UI()
{ u8g = new U8GLIB_SSD1306_128X64(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);  //create library object
  u8g->setColorIndex(1);      
}


void UI::drawIntro()  //TODO add drawing logic
{ 
 u8g->firstPage();  
   do {
      } while(u8g->nextPage());
  delay(100); //clrscr();

 u8g->firstPage();  
  do 
  { u8g->setPrintPos(7, 14); 
    u8g->setFont(bg7x14B);
    u8g->print("Здравей,"); 
    u8g->setPrintPos(7, 40); 
    u8g->print("Преслав Пейчев");    
  } while(u8g->nextPage());
  delay(2500);

 u8g->firstPage();  
  do 
  { u8g->setPrintPos(7, 14); 
    u8g->setFont(bg7x14B);
    u8g->print("Аз се казвам");
   
    u8g->setPrintPos(7, 40); 
    u8g->print("Робознайко!");    
  }  while(u8g->nextPage());
  delay(2000);

  u8g->firstPage();  
   do {
       u8g->drawBitmapP( 40, 0, 6, 64, logo);
      } while(u8g->nextPage());
  delay(2000);

  u8g->firstPage();  
  do 
  { u8g->setPrintPos(7, 14); 
    u8g->setFont(bg7x14B);
    u8g->print("Млад Изобретател");
   
    u8g->setPrintPos(15, 40); 
    u8g->print("Бъди различен!");    
  }  while(u8g->nextPage());
  delay(2000);

 u8g->firstPage();  
   do {
   } while(u8g->nextPage());
 

}

void UI::draw(Menu &menu)  //TODO add drawing logic
{  u8g->firstPage();  
   do {
    u8g->setFont(bg7x14B);
    u8g->setDefaultForegroundColor();

    switch (menu.currentPage()) {
        case Page::Overview:
            drawOverviewPage(menu,50,1,25.3);
            break;
        case Page::StopWatch:
            drawStopWatchPage(menu); //page 1
            break;
        case Page::Results:
            drawResultsPage(0); //page 2 
            break;
        case Page::Others:
            drawOthersPage(menu," ");  // page 3
            break;
       }
   } while(u8g->nextPage());

}

// predefined drawfunction

void UI::draw(Menu &menu, int s)  //TODO add drawing logic
{  u8g->firstPage();  
   do {
    u8g->setFont(bg7x14B);
    u8g->setDefaultForegroundColor();

    switch (menu.currentPage()) {
        case Page::Overview:
            drawOverviewPage(menu,50,1,25.3);
            break;
        case Page::StopWatch:
            drawStopWatchPage(menu); 
            break;
        case Page::Results:
            drawResultsPage(s);  //page 2
            break;
        case Page::Others:
            drawOthersPage(menu," ");
            break;
       }
   } while(u8g->nextPage());

}


void UI::draw(Menu &menu, char* codes)  //TODO add drawing logic
{  
  u8g->firstPage();  
   do {
    u8g->setFont(bg7x14B);
    u8g->setDefaultForegroundColor();

    switch (menu.currentPage()) {
        case Page::Overview:
            drawOverviewPage(menu,50,1,25.3);
            break;
        case Page::StopWatch:
            drawStopWatchPage(menu); 
            break;
        case Page::Results:
            drawResultsPage(0);  //page 2
            break;
        case Page::Others:
            drawOthersPage(menu,codes);
            break;
       }
   } while(u8g->nextPage());

}


void UI::drawOverviewPage(Menu &menu, int battery, bool charge, int temp) {
    // draw header
  uint8_t x,y;
  int l_battery=battery;
  bool l_charge=charge;
  double l_temp=temp;

  if(l_charge)u8g->drawBitmapP( 90, 2, 1, 8,bitmap_charging);
                            // x pos, ypos, width/8, heigh, name
  
    u8g->drawFrame(104,0,24,12); // battery frame
    u8g->drawBox(101,4,2,4); //pupkata 
    u8g->setFont(bg5x8); 
    if (l_battery==100) { x=108;  u8g->drawBox(106,2,l_battery/5,8); }
    else x=111;   
 
    String stringCode = String(l_battery); //convert int to char*
    char* newCode = (const char*) stringCode.c_str(); 

  if (l_battery<25) // %
  { u8g->setDefaultForegroundColor();
    u8g->drawBox(106,2,l_battery/5,8); //
    u8g->drawStr(x,9,newCode); 
   }
   else if (l_battery>75) // %
   { u8g->drawBox(106,2,l_battery/5,8);
     u8g->setDefaultBackgroundColor(); 
     u8g->drawStr(x,9,newCode);
   } 
   else 
   { u8g->setDefaultForegroundColor(); 
     u8g->drawBox(106,2,10,8);
    
     u8g->setDefaultBackgroundColor(); 
     u8g->drawStr(x,9,newCode);
     u8g->setDefaultForegroundColor(); 
     u8g->drawStr(x+6,9,&newCode[1]);
   }

  stringCode = String(temp); //convert int to char*
  newCode = (const char*) stringCode.c_str();
  u8g->drawStr(4,10,newCode);   // temperature 
  u8g->drawStr(15,10,"C");  
// end of drawIcons

   u8g->setFont(bg7x14B);
   const char *menu_strings[3] = { "Светлини", "Парктроник", "Дистанционно"};
   u8g->setDefaultForegroundColor(); 
  for( int i = 1; i <= MENU_ITEMS; i++ ) 
  { 
    x = (SCREEN_WIDTH-u8g->getStrWidth(menu_strings[i-1]))/2; // print menu items centred
    y= i*(SCREEN_HEIGHT-TEXT_HEIGHT)/MENU_ITEMS+2; 
   
    u8g->setDefaultForegroundColor();  
    if (static_cast<int>(menu.currentSelectedPage()) == i)  // check for currentSelectedPage, cast enum class to int
     { u8g->drawBox(0, y-1, SCREEN_WIDTH, TEXT_HEIGHT);   // draw box (pos x, pos y, lenght, height )    
       u8g->setDefaultBackgroundColor();   
     } 
   u8g->drawStr(x, y+9, menu_strings[i-1]);
   }     

}


void UI::drawStopWatchPage(Menu &menu) //first page Lights
{  u8g->drawStr(35,14,"Светлини"); 
   printSkier(menu.currentColor());  
   printFooter();
}

void UI::drawResultsPage(int dis) //second page Distance
{
  const char* newCode;   //header
  String stringCode; 
  u8g->setDefaultForegroundColor(); 
  u8g->drawStr(30,14,"Парктроник");

  u8g->drawStr(5,29,"Дистанция"); //left part of the screen
    u8g->setFont(bg9x18B); // bigger font

  stringCode = String(dis);
  newCode = (const char*) stringCode.c_str(); 
  u8g->setFont(bg7x14B);
  if(dis<100){ u8g->drawStr(23,47,newCode ); u8g->drawStr(43,47,"см"); } 
    else { u8g->drawStr(19,47,newCode ); u8g->drawStr(47,47,"см"); }
  
  u8g->drawTriangle(75,25, 115,25, 115,15); //x,y cordinates of 3 points
  u8g->drawBox(75,25,40,14); //x,y left upper corner ; widht; height
  u8g->drawTriangle(75,39, 115,39, 115,50); 
  u8g->drawFilledEllipse(115,33,6,16);  // centre; rx; ry
  
  if(dis<50 && dis>10) 
  { u8g->setDefaultBackgroundColor(); 
    u8g->drawBox(67+dis,15,4,34); 
    u8g->setDefaultForegroundColor();
  } 
   else if(dis<10) 
   { u8g->setDefaultBackgroundColor(); 
    u8g->drawBox(78,15,4,34); 
    u8g->setDefaultForegroundColor();
   } 

  printFooter();
}


void UI::drawOthersPage(Menu &menu, char* code) // 3th page
{
  char* newCode=code;  
  u8g->setDefaultForegroundColor();  
  u8g->drawStr(26,14,"Дистанционно"); // Header
  u8g->setFont(u8g_font_profont12); 
  u8g->drawStr(10,35,newCode);
  u8g->setFont(bg7x14B);
  printFooter();
}

void UI::printSkier(int color)
{  u8g->drawStr(10,28,"Цвят: ");  
   
 switch (color)
   { case 0: u8g->drawStr(50, 28,"Бял"); 
       break; 
     case 1: u8g->drawStr(50, 28,"Зелен"); 
       break;
     case 2: u8g->drawStr(50, 28,"Червен"); 
       break;
     case 3: u8g->drawStr(50, 28,"България"); 
       break;     
    } 
   
} 

void UI::printFooter()
{   u8g->setDefaultForegroundColor();
    u8g->drawBox(0, 53, 130, 17);   
    u8g->setDefaultBackgroundColor();
    u8g->drawStr(10, 63, "<    Назад    >");
}


void UI::sleep() 
{
   u8g->sleepOn();
} 

void UI::wake() 
{
   u8g->sleepOff();
} 