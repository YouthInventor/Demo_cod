#include "Menu.h"
#include "Arduino.h"

void Menu::setup()
{   m_currentPage=Page::Overview;
    m_currentSelectedPage=Page::StopWatch;
    m_currentColor=0; 
}

void Menu::previous() 
{  
// if(m_currentPage==Page::Overview) prevOverview();
  switch (m_currentPage)
 {   case Page::Overview:  prevOverview(); 
          break; //ready line
     case Page::StopWatch: prevColor();
          break;
        case Page::Results: //    nextResult();
            break;
        case Page::Others:
            break; 
    } 
}


void Menu::next() 
{ 
 // if(m_currentPage==Page::Overview) { nextOverview(); }

 switch (m_currentPage)
 {      case Page::Overview: nextOverview(); break; //ready line
        case Page::StopWatch: nextColor();
            break;
        case Page::Results:
        //    nextResult();
            break;
        case Page::Others:
            break; 
    } 
  
}


void Menu::prevOverview() {
 Serial.print("Selected page in Overview =");
    switch (m_currentSelectedPage) {
        case Page::StopWatch: { m_currentSelectedPage = Page::Others;  Serial.println("3");  }
             break;
        case Page::Results: { m_currentSelectedPage = Page::StopWatch; Serial.println("1");  }
             break;
        case Page::Others: { m_currentSelectedPage = Page::Results; Serial.println("2");  }
             break;
    } 

}


void Menu::nextOverview() {
 Serial.print("Selected page in Overview =");
    switch (m_currentSelectedPage) {
        case Page::StopWatch: { m_currentSelectedPage = Page::Results;  Serial.println("2");  }
             break;
        case Page::Results: { m_currentSelectedPage = Page::Others; Serial.println("3");  }
             break;
        case Page::Others: { m_currentSelectedPage = Page::StopWatch; Serial.println("1");  }
             break;
    } 
   

}

void Menu::select() {
    switch (m_currentPage) {
       case Page::Overview: selectOverview();  // 
            break;
       case Page::StopWatch:{ m_currentPage = Page::Overview; Serial.println("Back in Overview 1"); } // back button
            break;  
       case Page::Results: { m_currentPage = Page::Overview; Serial.println("Back in Overview 2"); }
            break;
       case Page::Others: { m_currentPage = Page::Overview; Serial.println("Back in Overview 3"); }
            break;
    }
   
}

void Menu::selectOverview() {
    m_currentPage = m_currentSelectedPage;  
   
    Serial.print("Selected page is ");
    switch (m_currentSelectedPage) {
        case Page::StopWatch: { m_currentSelectedPage = Page::StopWatch;  Serial.println("1");  }
             break;
        case Page::Results: { m_currentSelectedPage = Page::Results; Serial.println("2");  }
             break;
        case Page::Others: { m_currentSelectedPage = Page::Others; Serial.println("3");  }
             break;
    } 
}


Page Menu::currentPage ()
{  return m_currentPage; }

Page Menu::currentSelectedPage() {
    return m_currentSelectedPage;
}

void Menu::nextColor() {
    m_currentColor++;
   if(m_currentColor>3) m_currentColor=0;
}

void Menu::prevColor() {
    m_currentColor--;
   if(m_currentColor<0) m_currentColor=3;
}


int Menu::currentColor() {
   return m_currentColor;
}