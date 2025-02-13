#include <Arduino.h>
#include <SPI.h>
#include "RTClib.h"
#include <Adafruit_I2CDevice.h>
#include <7_seg_led_driver.h>

RTC_DS1307 rtc;
SevenSegLEDDriver segs;
int mindigit0, mindigit1, hourdigit0, hourdigit1, store;

void setup () {
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  segs.create();
  Serial.begin(57600);
  #ifndef ESP8266
  while (!Serial);
  #endif
  if (! rtc.begin()) {
    Serial.println("RTC not attached");
    Serial.flush();
    while (1) delay(10);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC not running");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop () {
    DateTime now = rtc.now();
    if (now.minute() != store){
      store = now.minute();
      segs.clear();
      segs.updateHour(now.hour()/10, 1);
      segs.updateHour(now.hour()%10, 0);
      segs.updateMinutes(now.minute()/10, 1);
      segs.updateMinutes(now.minute()%10, 0);
    delay(1000);
    }
}