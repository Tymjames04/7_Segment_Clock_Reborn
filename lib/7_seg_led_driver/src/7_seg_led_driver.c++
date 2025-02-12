#include <7_seg_led_driver.h>
#include <FastLED.h>
#define NUM_STRIPS 2
#define NUM_LEDS_PER_STRIP 56
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];
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
void push1(int pinside, int power);
void push2(int pinside, int power);
void push3(int pinside, int power);
void push4(int pinside, int power);
void push5(int pinside, int power);
void push6(int pinside, int power);
void push7(int pinside, int power);
void push8(int pinside, int power);
void push9(int pinside, int power);
void push0(int pinside, int power);

void SevenSegLEDDriver::create(){
    FastLED.addLeds<NEOPIXEL, 2>(leds[0], NUM_LEDS_PER_STRIP);
    FastLED.addLeds<NEOPIXEL, 3>(leds[1], NUM_LEDS_PER_STRIP);
}
void SevenSegLEDDriver::clear(){
    FastLED.clear();
}
void SevenSegLEDDriver::updatehour(int digit, int power){
    switch (digit)
    {
    case 1:
        push1(1,power);
        break;
    case 2:
        push2(1,power);
        break;
    case 3:
        push3(1,power);
        break;
    case 4:
        push4(1,power);
        break;
    case 5:
        push5(1,power);
        break;
    case 6:
        push6(1,power);
        break;
    case 7:
        push7(1,power);
        break;
    case 8:
        push8(1,power);
        break;
    case 9:
        push9(1,power);
        break;
    case 0:
        push0(1,power);
        break;
    }
    FastLED.show();
}
void SevenSegLEDDriver::updatemins(int digit, int power){
    FastLED.clear();
    switch (digit)
    {
    case 1:
        push1(0,power);
        break;
    case 2:
        push2(0,power);
        break;
    case 3:
        push3(0,power);
        break;
    case 4:
        push4(0,power);
        break;
    case 5:
        push5(0,power);
        break;
    case 6:
        push6(0,power);
        break;
    case 7:
        push7(0,power);
        break;
    case 8:
        push8(0,power);
        break;
    case 9:
        push9(0,power);
        break;
    case 0:
        push0(0,power);
        break;
    }
    FastLED.show();
}


void push1(int pinside, int power){
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
}
void push2(int pinside, int power){
    if(power == 1){
        for(unsigned int i = 0; i < (sizeof(leds2)/sizeof(leds2[0])) ; i++){
            leds[pinside][leds2[i]+28] = CRGB::Red;
        }
    }
    else{
        for(unsigned int i = 0; i < (sizeof(leds2)/sizeof(leds2[0])) ; i++){
            leds[pinside][leds2[i]] = CRGB::Red;
        }
    }
}
void push3(int pinside, int power){
    if(power == 1){
        for(unsigned int i = 0; i < (sizeof(leds3)/sizeof(leds3[0])) ; i++){
            leds[pinside][leds3[i]+28] = CRGB::Red;
        }
    }
    else{
        for(unsigned int i = 0; i < (sizeof(leds3)/sizeof(leds3[0])) ; i++){
            leds[pinside][leds3[i]] = CRGB::Red;
        }
    }
}
void push4(int pinside, int power){
    if(power == 1){
        for(unsigned int i = 0; i < (sizeof(leds4)/sizeof(leds4[0])) ; i++){
            leds[pinside][leds4[i]+28] = CRGB::Red;
        }
    }
    else{
        for(unsigned int i = 0; i < (sizeof(leds4)/sizeof(leds4[0])) ; i++){
            leds[pinside][leds4[i]] = CRGB::Red;
        }
    }
}
void push5(int pinside, int power){
    if(power == 1){
        for(unsigned int i = 0; i < (sizeof(leds5)/sizeof(leds5[0])) ; i++){
            leds[pinside][leds5[i]+28] = CRGB::Red;
        }
    }
    else{
        for(unsigned int i = 0; i < (sizeof(leds5)/sizeof(leds5[0])) ; i++){
            leds[pinside][leds5[i]] = CRGB::Red;
        }
    }
}
void push6(int pinside, int power){
    if(power == 1){
        for(unsigned int i = 0; i < (sizeof(leds6)/sizeof(leds6[0])) ; i++){
            leds[pinside][leds6[i]+28] = CRGB::Red;
        }
    }
    else{
        for(unsigned int i = 0; i < (sizeof(leds6)/sizeof(leds6[0])) ; i++){
            leds[pinside][leds6[i]] = CRGB::Red;
        }
    }
}
void push7(int pinside, int power){
    if(power == 1){
        for(unsigned int i = 0; i < (sizeof(leds7)/sizeof(leds7[0])) ; i++){
            leds[pinside][leds7[i]+28] = CRGB::Red;
        }
    }
    else{
        for(unsigned int i = 0; i < (sizeof(leds7)/sizeof(leds7[0])) ; i++){
            leds[pinside][leds7[i]] = CRGB::Red;
        }
    }
}
void push8(int pinside, int power){
    if(power == 1){
        for(unsigned int i = 0; i < (sizeof(leds8)/sizeof(leds8[0])) ; i++){
            leds[pinside][leds8[i]+28] = CRGB::Red;
        }
    }
    else{
        for(unsigned int i = 0; i < (sizeof(leds8)/sizeof(leds8[0])) ; i++){
            leds[pinside][leds8[i]] = CRGB::Red;
        }
    }
}
void push9(int pinside, int power){
    if(power == 1){
        for(unsigned int i = 0; i < (sizeof(leds9)/sizeof(leds9[0])) ; i++){
            leds[pinside][leds9[i]+28] = CRGB::Red;
        }
    }
    else{
        for(unsigned int i = 0; i < (sizeof(leds9)/sizeof(leds9[0])) ; i++){
            leds[pinside][leds9[i]] = CRGB::Red;
        }
    }
}
void push0(int pinside, int power){
    if(power == 1){
        for(unsigned int i = 0; i < (sizeof(leds0)/sizeof(leds0[0])) ; i++){
            leds[pinside][leds0[i]+28] = CRGB::Red;
        }
    }
    else{
        for(unsigned int i = 0; i < (sizeof(leds0)/sizeof(leds0[0])) ; i++){
            leds[pinside][leds0[i]] = CRGB::Red; 
        }
    }        
}