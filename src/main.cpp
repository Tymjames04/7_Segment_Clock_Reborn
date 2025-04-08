#include <Arduino.h>
#include <SPI.h>
#include "RTClib.h"
#include <Adafruit_I2CDevice.h>
#include <7_seg_led_driver.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>

const char* ssid = "DaNetwork";
const char* password = "TBirD0408";
AsyncWebServer server(80);

RTC_DS1307 rtc;
SevenSegLEDDriver segs;
int mindigit0, mindigit1, hourdigit0, hourdigit1, store;
int red = 255, green = 0, blue = 0, changed = 0; 

String HTMLSetup(){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LED Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: left;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<h1>Clock Controls!</h1>\n";
  ptr +="<body>\n";
  ptr +="<label for=\"colors\">Select your color:</label><select name=\"colors\" id=\"colors\" onchange=\"setColor()\">";
  ptr +="<option value=\"red\">Red</option>";
  ptr +="<option value=\"green\">Green</option>";
  ptr +="<option value=\"purple\">Purple</option>";
  ptr +="<option value=\"yellow\">Yellow</option>";
  ptr +="<option value=\"orange\">Orange</option>";
  ptr +="<option value=\"white\">White</option>";
  ptr +="<option value=\"blue\">Blue</option></select>\n";
  ptr +="<script>function setColor() {var color = document.getElementById(\"colors\").value;\n";
  ptr +="var xhr = new XMLHttpRequest();xhr.open(\"GET\", \"/setColor?color=\" + color, true);xhr.send();}\n";
  ptr +="</script>\n";
  ptr +="</body></html>\n";
  return ptr;
}

void setColor(String color) {
  if (color == "red") {
    red = 255;
    green = 0;
    blue = 0;
  } else if (color == "green") {
    red = 0;
    green = 255;
    blue = 0;
  } else if (color == "blue") {
    red = 0;
    green = 0;
    blue = 255;
  } else if (color == "purple") {
    red = 255;
    green = 0;
    blue = 255;
  } else if (color == "white") {
    red = 255;
    green = 255;
    blue = 255;
  } else if (color == "orange") {
    red = 255;
    green = 127;
    blue = 0;
  } else if (color == "yellow") {
    red = 255;
    green = 255;
    blue = 0;
  }
  changed = 1;
}

void setup () {
  segs.create();
  Serial.begin(57600);
  WiFi.begin(ssid, password);
  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->send(200, "text/html", HTMLSetup());
  });

  server.on("/setColor", HTTP_GET, [](AsyncWebServerRequest* request) {
    if (request->hasParam("color")) {
      String color = request->getParam("color")->value();
      setColor(color);
      request->send(200, "text/plain", "Color set to " + color);
    } else {
      request->send(400, "text/plain", "Color not specified");
    }
  });

  server.begin();

  #ifndef ESP8266
  while (!Serial);
  #endif

  if (! rtc.begin()) {
    Serial.flush();
    while (1) delay(10);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC not running");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  
}

void loop () {
    DateTime now = rtc.now();
    if ((now.minute() != store)||(changed == 1)){
      store = now.minute();
      segs.clear();
      segs.updateColors(red,green,blue);
      segs.updateHour(now.hour()/10, 1);
      segs.updateHour(now.hour()%10, 0);
      segs.updateMinutes(now.minute()/10, 1);
      segs.updateMinutes(now.minute()%10, 0);
      changed = 0;
      delay(1000);
    }
}