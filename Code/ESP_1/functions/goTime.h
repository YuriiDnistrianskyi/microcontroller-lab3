#ifndef GOTIME_H
#define GOTIME_H

#include "finishTimer.h"

extern uint32_t lastTimeCheck;
extern Timer timer1;
extern Timer timer2;

void goTime(uint8_t timerNumber)
{
    uint32_t currentTime = millis();
    bool status;

    if (currentTime - lastTimeCheck >= 1000)
    {
        lastTimeCheck = currentTime;
        if (timerNumber == 1)
        {
            timer1.goTimer();
            status = timer1.finished;
        }
        else
        {
            timer2.goTimer();
            status = timer2.finished;
        }

        if (status)
            finishTimer(); // сигнал про зікінчення 
    }
}


#endif // GOTIME_H