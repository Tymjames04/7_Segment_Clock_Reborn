# 7-Segment Clock Reborn
My first attempt at a full implementation of a 7-segment style clock built with individually addressable LEDs and 3D printed housings left more to be desired in terms of the final product. Here is my 2nd attempt at creating my dream wall clock from scratch. If you would like to also build this clock youre free to use the code and files I have created for your own personal use. NOTE: My code was built using the PlatformIO extension on VSCode and is not optimized to be widely adopeted. It likely wont be plug and play with other boards so a little touchup will be needed. 

## Design Process
### 1. Rough circuit prototypes
- Utilized PlatformIO and VSCode to program Arduino Uno and DS1307 RTC to drive a single 7-seg display as proof of concept.

<img src="https://github.com/Chompinz/7_Segment_Clock_Reborn/blob/main/.photos/IMG_8383.jpg?raw=true" width="500">

- Updated code to now work on 4 digit 7-segment display as the final product will be similar to that, just larger and illuminated with LEDs.

<img src="https://github.com/Chompinz/7_Segment_Clock_Reborn/blob/main/.photos/IMG_8385.jpg?raw=true" width="500">

### 2. 3D modeling and printing
- Created the model and printed a 40% scale model of it to ensure it fit together.

<img src="https://github.com/Chompinz/7_Segment_Clock_Reborn/blob/main/.photos/IMG_8395.jpg?raw=true" width="500">

### 3. Codeing and Optimization
- I attempted to use the code that had been used to drive the simple 4 digit display but that proved to be inadequate. A 7_seg_led_library library was created to bridge the gap between main and the fastLED library. More documentation can be found within the code itself as well as the [readme](https://github.com/Tymjames04/7_Segment_Clock_Reborn/blob/main/lib/7_seg_led_driver/7_seg_led_driver.md) for the library.

- When built and uploaded to Arduino UNO the correct ones place digit of the current minute was shown.
  
<img src="https://github.com/Tymjames04/7_Segment_Clock_Reborn/blob/main/.photos/IMG_8546.jpg?raw=true" width="500">

### 4. Final Construction
