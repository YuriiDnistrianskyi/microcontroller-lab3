#ifndef TIMER_H
#define TIMER_H

#include "TimerState.h"

class Timer {
    private:
        uint8_t hours : 7;
        uint8_t minutes : 6;
        uint8_t seconds : 6;
        TimerState state;
        void checkTimer();

    public:
        Timer();
        void setHours(uint8_t h);
        void setMinutes(uint8_t m);
        void onTimer();
        uint8_t getHours();
        uint8_t getMinutes();
        uint8_t getSeconds();
        TimerState getState();
        void goTimer();
};

Timer::Timer() {
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
    this->state = off;
}

void Timer::setHours(uint8_t h) 
{
    this->hours = h;
    checkTimer();
}

void Timer::setMinutes(uint8_t m) 
{
    this->minutes = m;
    checkTimer();
}

void Timer::onTimer()
{
    this->status = on;
}

uint8_t Timer::getHours()
{
    return this->hours;
}

uint8_t Timer::getMinutes()
{
    return this->minutes;
}

uint8_t Timer::getSeconds()
{
    return this->seconds;
}

TimerState Timer::getState()
{
    return this->state;
}

void Timer::checkTimer() 
{
    if (this->hours <= 0 && this->minutes <= 0 && this->seconds <= 0) 
    {
        this->isFinished = true;
    } 
    else 
    {
        this->isFinished = false;
    }
}


void Timer::goTimer() {
    this->state = on; //
    if (this->seconds > 0)
    {
        this->seconds--;
    }
    else if (this->seconds <= 0 && this->minutes > 0) 
    {
        this->seconds = 59;
        this->minutes--;
        if (this->minutes <= 0 && this->hours > 0) 
        {
            this->minutes = 59;
            this->hours--;
        } 
    }
    else 
    {
        this->state = finished;
    }

}

#endif // TIMER_H