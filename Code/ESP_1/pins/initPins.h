#ifndef INITPINS_H
#define INITPINS_H

#include "pins.h"
#include "../Models/ProgramState.h" //
#include "../Models/TimerState.h" //


#define DEBOUNCE_TIME 50

extern 
extern uint8_t timerNumber;
extern ProgramState programState;

volatile uint32_t lastDebounceTime1 = 0;
volatile uint32_t lastDebounceTime2 = 0;
volatile uint32_t lastDebounceTime3 = 0;
volatile uint32_t lastDebounceTime4 = 0;

void IRAM_ATTR button1Handler() 
{
    uint32_t = currentTime = millis();

    if ((currentTime - lastDebounceTime1) > DEBOUNCE_TIME)
    {
        lastDebounceTime1 = currentTime;
        timerNumber = !timerNumber;
    }
}

void IRAM_ATTR button2Handler() 
{
    uint32_t = currentTime = millis();

    if ((currentTime - lastDebounceTime2) > DEBOUNCE_TIME)
    {
        lastDebounceTime2 = currentTime;
        programState = hour;
    }
}

void IRAM_ATTR button3Handler() 
{
    uint32_t = currentTime = millis();

    if ((currentTime - lastDebounceTime3) > DEBOUNCE_TIME)
    {
        lastDebounceTime3 = currentTime;
        programState = minute;
    }
}

void IRAM_ATTR button4Handler() 
{
    uint32_t = currentTime = millis();

    if ((currentTime - lastDebounceTime4) > DEBOUNCE_TIME)
    {
        lastDebounceTime4 = currentTime;

        Timer currentTimer =  (timerNumber == 0) ? timer1 : timer2;
        // TimerState timerState = currentTimer.getState();
        if (programState == go) 
        {
            // скидавння в 0
        }
        else 
        {
            currentTimer.onTimer();
            programState = go;
        }
    }
}

void initPins()
{
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    pinMode(button3, INPUT);
    pinMode(button4, INPUT);

    attachInterrupt(digitalPinToInterrupt(button1), button1Handler, RISING);
    attachInterrupt(digitalPinToInterrupt(button2), button2Handler, RISING);
    attachInterrupt(digitalPinToInterrupt(button3), button3Handler, RISING);
    attachInterrupt(digitalPinToInterrupt(button4), button4Handler, RISING);
}

#endif // INITPINS_H