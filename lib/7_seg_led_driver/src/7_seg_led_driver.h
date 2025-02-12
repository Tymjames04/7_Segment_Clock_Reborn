#ifndef __7_SEG_LED_DRIVER_H
#define __7_SEG_LED_DRIVER_H

class SevenSegLEDDriver {
public:
    void updatehour(int dig, int place);
    void updatemins(int dig, int place);
    void create();
    void clear();
};

#endif // __7_SEG_LED_DRIVER_H