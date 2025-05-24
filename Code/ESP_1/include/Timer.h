#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer {
    private:
        uint8_t hours : 7;
        uint8_t minutes : 6;
        uint8_t seconds : 6;
        bool isFinished;

    public:
        Timer();
        void setHours(uint8_t h);
        void setMinutes(uint8_t m);
        void reset();
        uint8_t getHours(); //
        uint8_t getMinutes(); //
        uint8_t getSeconds(); //
        String getTime();
        bool getFinished();
        void goTimer();
};

#endif // TIMER_H