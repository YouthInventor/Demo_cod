
#include "fonts/IRremote/src/IRremote.h"
#include "Menu.h"

class IR{
public:
    IR();
    char* decode();
   // void lightLed(Menu &menu);
private:
    int a;
    IRrecv *irrecv;
    decode_results results;
    
    //static Timer *s_timers[3];
};

