#ifndef GOTIME_H
#define GOTIME_H

#include "updateDisplay.h"
#include "finishTimer.h"
#include "../Models/TimerState.h"

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
        TimerState timerState = timer.getStatus();
        updateDisplay(&timer);

        if (timerState == finished)
            finishTimer();
    }
}


#endif // GOTIME_H