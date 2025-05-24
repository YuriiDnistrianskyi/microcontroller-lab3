#include "../include/Timer.h"

Timer::Timer() {
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
    this->isFinished = false;
}

void Timer::setHours(uint8_t h) 
{
    this->hours = h;
    this->isFinished = false;
}

void Timer::setMinutes(uint8_t m) 
{
    this->minutes = m;
    this->isFinished = false;
}

void Timer::reset()
{
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
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

String Timer::getTime()
{
    String time = String(this->hours) + ":" + String(this->minutes) + ":" + String(this->seconds);
    return time;
}

bool Timer::getFinished()
{
    return this->isFinished;
}

void Timer::goTimer() {
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
        this->isFinished = true;
    }
}