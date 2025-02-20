/*
Holds all implementations of definitions from header file.
All LED values associated with each integer value are stored in arrays that can be called by pushUpdate.
*/
#include <7_seg_led_driver.h>
#include <FastLED.h>
#define NUM_STRIPS 2
#define NUM_LEDS_PER_STRIP 56
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];
void pushUpdate(int value, int pinside, int power);
int leds1[8] = {0,1,2,3,16,17,18,19};
int leds2[20] = {7,6,5,4,12,13,14,15,3,2,1,0,27,26,25,24,23,22,21,20};
int leds3[20] = {7,6,5,4,3,2,1,0,12,13,14,15,23,22,21,20,19,18,17,16};
int leds4[16] = {8,9,10,11,12,13,14,15,16,17,18,19,3,2,1,0};
int leds5[20] = {7,6,5,4,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
int leds6[24] = {4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
int leds7[12] = {0,1,2,3,4,5,6,7,16,17,18,19};
int leds8[28] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
int leds9[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
int leds0[24] = {0,1,2,3,4,5,6,7,8,9,10,11,16,17,18,19,20,21,22,23,24,25,26,27};

void SevenSegLEDDriver::create(){
    FastLED.addLeds<NEOPIXEL, 4>(leds[0], NUM_LEDS_PER_STRIP);
    FastLED.addLeds<NEOPIXEL, 2>(leds[1], NUM_LEDS_PER_STRIP);
    FastLED.setBrightness(128);
}
void SevenSegLEDDriver::clear(){
    FastLED.clear();
}
//Uses switch functions to pass correct values into pushUpdate depending on digit parameter. 
void SevenSegLEDDriver::updateHour(int digit, int power){
    switch (digit)
    {
    case 1:
        pushUpdate(1,1,power);
        break;
    case 2:
        pushUpdate(2,1,power);
        break;
    case 3:
        pushUpdate(3,1,power);
        break;
    case 4:
        pushUpdate(4,1,power);
        break;
    case 5:
        pushUpdate(5,1,power);
        break;
    case 6:
        pushUpdate(6,1,power);
        break;
    case 7:
        pushUpdate(7,1,power);
        break;
    case 8:
        pushUpdate(8,1,power);
        break;
    case 9:
        pushUpdate(9,1,power);
        break;
    case 0:
        pushUpdate(0,1,power);
        break;
    }
    FastLED.show();
}
//Uses switch functions to pass correct values into pushUpdate depending on digit parameter. 
void SevenSegLEDDriver::updateMinutes(int digit, int power){
    switch (digit)
    {
    case 1:
        pushUpdate(1,0,power);
        break;
    case 2:
        pushUpdate(2,0,power);
        break;
    case 3:
        pushUpdate(3,0,power);
        break;
    case 4:
        pushUpdate(4,0,power);
        break;
    case 5:
        pushUpdate(5,0,power);
        break;
    case 6:
        pushUpdate(6,0,power);
        break;
    case 7:
        pushUpdate(7,0,power);
        break;
    case 8:
        pushUpdate(8,0,power);
        break;
    case 9:
        pushUpdate(9,0,power);
        break;
    case 0:
        pushUpdate(0,0,power);
        break;
    }
    FastLED.show();
}
// Takes in 3 parameters and then turn on all needed LEDS based on array of needed values. 
// -Value: Integer of what time needs to be updated onto the LEDS.
// -Pinside: Determines if hour or minute segments need to be updated. 1 = Hour and 0 = Minute.
// -Power: updates tens place if power = 1 and ones place segment if place = 0.
void pushUpdate(int value, int pinside, int power){
    switch (value)
    {
    case 1:
        if(pinside == 0){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][55-leds1[i]] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][27-leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
        else if(pinside == 1){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]+28] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
    case 2:
        if(pinside == 0){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][55-leds1[i]] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][27-leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
        else if(pinside == 1){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]+28] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
    case 3:
        if(pinside == 0){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][55-leds1[i]] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][27-leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
        else if(pinside == 1){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]+28] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
    case 4:
        if(pinside == 0){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][55-leds1[i]] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][27-leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
        else if(pinside == 1){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]+28] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
    case 5:
        if(pinside == 0){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][55-leds1[i]] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][27-leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
        else if(pinside == 1){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]+28] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
    case 6:
        if(pinside == 0){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][55-leds1[i]] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][27-leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
        else if(pinside == 1){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]+28] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
    case 7:
        if(pinside == 0){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][55-leds1[i]] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][27-leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
        else if(pinside == 1){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]+28] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]] = CRGB::Red;
                }
            }
            break;
        } 
    case 8:
        if(pinside == 0){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][55-leds1[i]] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][27-leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
        else if(pinside == 1){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]+28] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
    case 9:
        if(pinside == 0){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][55-leds1[i]] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][27-leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
        else if(pinside == 1){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]+28] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]] = CRGB::Red;
                }
            }
            break;
        }  
    case 0:
        if(pinside == 0){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][55-leds1[i]] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][27-leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
        else if(pinside == 1){
            if(power == 1){
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]+28] = CRGB::Red;
                }
            }
            else{
                for(unsigned int i = 0; i < (sizeof(leds1)/sizeof(leds1[0])) ; i++){
                    leds[pinside][leds1[i]] = CRGB::Red;
                }
            }
            break;
        }
    }
}
