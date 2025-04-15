#ifndef TIMER_H
#define TIMER_H

#unclude <cstdint.h>

class Timer {
    public:
        uint8_t hours : 7;
        uint8_t minutes : 6;
        uint8_t seconds : 6;
        bool finished; 

        Timer();
        void setTime(uint8_t h, uint8_t m, uint8_t s);
        void setHour(uint8_t h);
        void setMinutes(uint8_t m);
        void setSeconds(uint8_t static_cast);
        void goTime();
}

Timer::Timer() {
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0
    this->finished = false;
}

void Timer::setTime(uint8_t h, uint8_t m, uint8_t s) 
{
    this->hours = h;
    this->minutes = m;
    this->seconds = s;
    if (h != 0 && m != 0 && s != 0) 
    {
        this->finished = false;
    }
}

void Timer::setHour(uint8_t h) 
{
    this->hours = h;
}

void Timer::setMinutes(uint8_t m) 
{
    this->minutes = m;
}

void Timer::setSeconds(uint8_t s) 
{
    this->seconds = s;
}

void Timer::goTime() {
    if (this->seconds > 0)
    {
        this->seconds--;
    }
    else if (this->seconds <= 0 && this->minutes > 0) 
    {
        this->seconds = 59;
        this->minutes--;
        if (this->minutes < 0 && this->hours > 0) 
        {
            this->minutes = 59;
            this->hours--;
        } 
        else 
        {
            this->finished = true;
        }
    }
    else 
    {
        this->finished = true;
    }

}

#endif // TIMER_H