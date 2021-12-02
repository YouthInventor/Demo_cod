
#include "IR.h"
#include "Arduino.h"

 IR :: IR()
{ 
 irrecv = new IRrecv(4);
 irrecv->enableIRIn();
 
 }
char* IR :: decode()
{ char* e = 'e';
 String stringCode;
 char* newCode;
  if(irrecv->decode(&results)) 
   { 
    stringCode = String(results.value,HEX);
    newCode = (char*) stringCode.c_str();  
    //Serial.println(results.value, HEX);
    irrecv->resume();
    return newCode;
   }
   else return e;
}

/* ако има нов код го записва в променлива прайвит +
функция, коята извиква връща като резултат тази променлива */