#include <Arduino.h>

#include "pins/initPins.h"
#include "espServer/espServer.h"

#include "Models/Timer.h"
#include "Models/State.h"

#include "functions/goTime.h"
#include "functions/setTime.h"


Timer timer1;
Timer timer2;
State state;
uint8_t timerNumber = 0;
uint32_t lastTimeCheck = 0;

void setup() 
{
  Serial.begin(115200);
  initWifi();
  initPins();
}

void loop()
{
  Timer &currentTimer = (timerNumber == 0) ? timer1 : timer2;

  switch(state) 
  {
    case wait: // можна на default зробити
      // просто відображує обраний таймер на досплеї,
      break;
    case go:
      // працює обраний таймер
      goTime(currentTimer); break;
    case hour:
      // змінює години
      setHours(currentTimer); break;
    case minutes:
      // змінєю хвилини
      setMinutes(currentTimer); break;
  }
}
