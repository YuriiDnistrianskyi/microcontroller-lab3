#ifndef GOTIME_H
#define GOTIME_H

extern uint32_t lastTimeCheck;
extern Timer timer1;
extern Timer timer2;

void goTime(uint8_t timerNumber)
{
    uint32_t currentTime = millis();

    if (currentTime - lastTimeCheck >= 1000)
    {
        if (timerNumber == 1)
        {
            // timer1.goTime
        }
        else
        {
            // timer2.goTime
        }

        // timerNumber == 1 ? timer1.goTime() : timer2.goTime();
    }
}

void checkTimersStatus(uint8_t timerNumber)
{
    bool status = timerNumber == 1 ? timer1.finished : timer2.finished;
}

#endif // GOTIME_H