#ifndef SETTIME_H
#define SETTIME_H

void setHours(Timer &timer) {
    uint8_t value = analogRead(encoderPin); // 0 : 255

    timer.setHours(value / 2.56); // 0 : 99
}

void setMinutes(Timer &timer) {
    uint8_t value = analogRead(encoderPin); // 0 : 255

    timer.setMinutes(value / 4.25); // 0 : 59
}

#endif // SETTIME_H