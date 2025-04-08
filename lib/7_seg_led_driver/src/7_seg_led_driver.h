/*
updateHour(int digit, int power): updates either of the hour digits to the value of digit. Updates tens place segment if power = 1 and ones place segment if power = 0.
updateMinutes(int digit, int power): updates either of the minute digits to the value of digit. Updates tens place segment if power = 1 and ones place segment if power = 0.
create(): Uses fastLED to create two LED controllers and add all needed LEDS to them. 
clear(): Runs fastLED.clear()
*/
#ifndef __7_SEG_LED_DRIVER_H
#define __7_SEG_LED_DRIVER_H

class SevenSegLEDDriver {
public:
    void updateHour(int digit, int place);
    void updateMinutes(int digit, int place);
    void create();
    void clear();
    void updateColors(int red, int green, int blue);
};

#endif