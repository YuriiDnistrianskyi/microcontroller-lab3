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

    if (currentTime - lastTimeCheck >= 1000)
    {
        lastTimeCheck = currentTime;
        
        timer.goTimer();
        updateDisplay(&timer);

        bool isFinishedTimer = timer.getFinished();

        if (isFinishedTimer == 1)
        {
            finishTimer();
            // timer->isFinished = false;
        }
    }
}


#endif // GOTIME_H