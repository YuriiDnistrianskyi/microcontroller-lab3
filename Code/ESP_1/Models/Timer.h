#ifndef TIMER_H
#define TIMER_H

class Timer {
    private:
        uint8_t hours : 7;
        uint8_t minutes : 6;
        uint8_t seconds : 6;
        bool isFinished; 
        void checkTimer();

    public:
        Timer();
        void setHours(uint8_t h);
        void setMinutes(uint8_t m);
        bool getFinished();
        void goTimer();
};

Timer::Timer() {
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
    this->isFinished = false;
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

bool Timer::getFinished()
{
    return this->isFinished;
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

#endif // TIMER_H