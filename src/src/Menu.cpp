#include "Menu.h"
#include "Arduino.h"

void Menu::setup()
{   m_currentPage=Page::Overview;
    m_currentSelectedPage=Page::StopWatch;
    m_currentColor=0; 
}

void Menu::previous() 
{  
  switch (m_currentPage)
 {   case Page::Overview:  prevOverview(); 
          break; 
     case Page::StopWatch: prevColor();  //first page
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
 
    switch (m_currentSelectedPage) {
        case Page::StopWatch: { m_currentSelectedPage = Page::Results;    }
             break;
        case Page::Results: { m_currentSelectedPage = Page::Others;   }
             break;
        case Page::Others: { m_currentSelectedPage = Page::StopWatch;  }
             break;
    } 
   

}

void Menu::select() {
    switch (m_currentPage) {
       case Page::Overview: selectOverview();  // 
            break;
       case Page::StopWatch:{ m_currentPage = Page::Overview;  } // back button
            break;  
       case Page::Results: { m_currentPage = Page::Overview; }
            break;
       case Page::Others: { m_currentPage = Page::Overview;  }
            break;
    }
   
}

void Menu::selectOverview() {
    m_currentPage = m_currentSelectedPage;  

    switch (m_currentSelectedPage) {
        case Page::StopWatch: { m_currentSelectedPage = Page::StopWatch;   }
             break;
        case Page::Results: { m_currentSelectedPage = Page::Results;   }
             break;
        case Page::Others: { m_currentSelectedPage = Page::Others;   }
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