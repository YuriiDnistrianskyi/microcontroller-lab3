#ifndef UPDATEDISPLAY_H
#define UPDATEDISPLAY_H

#include "../pins/pins.h" // for display pins

void updateDisplay(Timer &timer)
{
    uint8_t hours = timer.getHours();
    uint8_t minutes = timer.getMinutes();
    uint8_t seconds = timer.getSeconds();

    // display
}

#endif // UPDATEDISPLAY_H