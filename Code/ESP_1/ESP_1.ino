#include <Arduino.h>

#include "pins/initPins.h"
#include "espServer/espServer.h"

#include "Models/Timer.h"
#include "Models/ProgramState.h"

#include "functions/goTime.h"
#include "functions/setTime.h"


Timer timer1;
Timer timer2;
ProgramState programState;
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

  switch(programState) 
  {
    case wait: // можна на default зробити
      // просто відображує таймери (обраний таймер підсвічується)
      break;
    case go:
      // працює обраний таймер
      goTime(currentTimer); break;
    case hour:
      // змінює години
      setHours(currentTimer); break;
    case minute:
      // змінєю хвилини
      setMinutes(currentTimer); break;
  }
}
