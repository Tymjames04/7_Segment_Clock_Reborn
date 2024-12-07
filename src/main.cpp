#include <Arduino.h>
#include <SPI.h>
#include <RTClib.h>
#include <SevSeg.h>

SevSeg sevseg1; 
RTC_DS1307 rtc;
int tot_time;

void setup () {
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected
  sevseg1.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg1.setBrightness(90); 

  if (!rtc.begin()) {
    Serial.flush();
    while (1) delay(10);
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop () {
    DateTime now = rtc.now();
    int cur_time_min = now.minute();
    int cur_time_hour = now.hour()*100;
    tot_time = cur_time_min + cur_time_hour;
  
    sevseg1.setNumber(tot_time);
    sevseg1.refreshDisplay();
    Serial.println();
}