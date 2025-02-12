#ifndef __7_SEG_LED_DRIVER_H
#define __7_SEG_LED_DRIVER_H

class SevenSegLEDDriver {
public:
    void updateHour(int digit, int place);
    void updateMinutes(int digit, int place);
    void create();
    void clear();
};

#endif // __7_SEG_LED_DRIVER_H