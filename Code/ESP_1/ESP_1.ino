#include <Arduino.h>

#include "include/initPins.h"
#include "include/espServer.h"

#include "include/Timer.h"
#include "include/ProgramState.h"

#include "include/timerFunc.h"

Timer timer1;
Timer timer2;
ProgramState programState = wait;
uint8_t timerNumber = 0;

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
    case wait: // можна на default зробити або (якщо дії взагалі не виконуються), то прибрати
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
