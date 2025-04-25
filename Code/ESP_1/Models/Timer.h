#ifndef TIMER_H
#define TIMER_H

class Timer {
    private:
        uint8_t hours : 7;
        uint8_t minutes : 6;
        uint8_t seconds : 6;
        void checkTimer();

    public:
        bool finished; 

        Timer();
        void setHour(uint8_t h);
        void setMinutes(uint8_t m);
        void goTimer();
};

Timer::Timer() {
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
    this->finished = false;
}


void Timer::setHour(uint8_t h) 
{
    this->hours = h;
    checkTimer();
}

void Timer::setMinutes(uint8_t m) 
{
    this->minutes = m;
    checkTimer();
}

void Timer::checkTimer() 
{
    if (this->hours <= 0 && this->minutes <= 0 && this->seconds <= 0) 
    {
        this->finished = true;
    } 
    else 
    {
        this->finished = false;
    }
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
        this->finished = true;
    }

}

#endif // TIMER_H