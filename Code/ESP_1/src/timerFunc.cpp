#include <Arduino.h>

#include "../include/timerFunc.h"

#include "../include/config.h"
#include "../include/Timer.h"
#include "../include/updateDisplay.h"

uint32_t lastTimeCheck;

void goTime(Timer &timer)
{
    uint32_t currentTime = millis();

    if (currentTime - lastTimeCheck >= 1000)
    {
        lastTimeCheck = currentTime;
        
        timer.goTimer();
        Timer &timerToDisplay = timer;
        updateDisplay(timerToDisplay);

        bool isFinishedTimer = timer.getFinished();

        if (isFinishedTimer == 1)
        {
            finishTimer();
            // timer->isFinished = false;
            // programState = wait;
        }
    }
}

void setHours(Timer &timer) {
    uint8_t value = analogRead(encoderPin); // 0 : 255

    timer.setHours(value / 2.56); // 0 : 99
    // flag
    updateDisplay(timer);
}

void setMinutes(Timer &timer) {
    uint8_t value = analogRead(encoderPin); // 0 : 255

    timer.setMinutes(value / 4.25); // 0 : 59
    // flag
    updateDisplay(timer);
}

void finishTimer() {
    
}
