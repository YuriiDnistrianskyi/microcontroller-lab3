#include <Arduino.h>

#include "espServer/espServer.h"
#include "Models/Timer.h"
#include "functions/goTime.h"

Timer timer1;
Timer timer2;
uint8_t timerNumber;
uint32_t lastTimeCheck = 0;

bool go = false;

void initPins()
{

}

void setup() 
{
  Serial.begin(115200);
  initWifi();
  initPins();
}

void loop()
{
  if (go)
  {
    goTime();
  }
}
