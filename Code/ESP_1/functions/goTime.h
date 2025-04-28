#ifndef GOTIME_H
#define GOTIME_H

#include "updateDisplay.h"
#include "finishTimer.h"

extern uint32_t lastTimeCheck;
extern Timer timer1;
extern Timer timer2;

void goTime(Timer &timer)
{
    uint32_t currentTime = millis();
    bool status;

    if (currentTime - lastTimeCheck >= 1000)
    {
        lastTimeCheck = currentTime;
        
        timer.goTimer();
        status = timer.getFinished();
        updateDisplay(timer);


        if (status)
            finishTimer();
    }
}


#endif // GOTIME_H