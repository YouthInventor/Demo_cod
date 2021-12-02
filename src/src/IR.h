
#include "fonts/IRremote/src/IRremote.h"
#include "Menu.h"

class IR{
public:
    IR();
    char* decode();
private:
    int a;
    IRrecv *irrecv;
    decode_results results;
    
};

