#pragma once
#include "Menu.h"

class Distance{
public:
    Distance();
    int measure();
   
private:
    int m_echoPin;
    int m_trigerPin;
};