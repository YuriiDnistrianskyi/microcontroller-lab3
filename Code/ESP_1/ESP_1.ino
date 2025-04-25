#include <Arduino.h>

#include "espServer/espServer.h"
#include "Models/Timer.h"
#include "Models/State.h"

#include "functions/goTime.h"
#include "functions/setTime.h"

#include "pins/initPins.h"

Timer timer1;
Timer timer2;
State state;
uint8_t timerNumber = 1;
uint32_t lastTimeCheck = 0;


void setup() 
{
  Serial.begin(115200);
  initWifi();
  initPins();
  // timer1.setTime(0, 1, 10);
}

void loop()
{
  switch(state) 
  {
    case wait: // можна на default зробити
      // просто відображує обраний таймер на досплеї,
      initWifi();
      break;
    case go:
      // працює обраний таймер
      goTime(timerNumber); break;
    case hour:
      // змінює години
      setHour(timerNumber); break;
    case minutes:
      // змінєю хвилини
      setMinutes(timerNumber); break;
  }
}
