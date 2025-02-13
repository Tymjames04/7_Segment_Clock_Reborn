## 7_seg_led_driver
### Credits
 - fastLED by Daniel Garcia and Zach Vorhies
### Overview
This library works by importing the fastLED library to update 7-segment displays that are comprised of standard LED strips. Integers values for all 4 segments are passed into updateMinute and updateHour functions which then change LEDs based on said values. Those functions also take in a "power" value that indicates if its the 1st or 2nd value of the minute or minute segments. 