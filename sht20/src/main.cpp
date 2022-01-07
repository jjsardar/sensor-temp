#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <splash.h>
#include <SHT2x.h>
#include <Adafruit_I2CDevice.h>
#include "Wire.h"
Adafruit_SSD1306 display(-1);
SHT2x sht;
float temperature = sht.getTemperature();
float humidity = sht.getHumidity();
void setup() {
  sht.begin();
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 28);
  display.println("Hello My First app for karamozi");
  display.display();
  delay(2000);
  display.clearDisplay();
  Serial.begin(9600);
  Serial.println("SHT20 Start");
  float temperature = sht.getTemperature();
  
}

void loop() {
  display.setCursor(0, 0);
  display.println(temperature, DEC);
  display.setCursor(0, 28);
  display.println(humidity, DEC);
  display.display();
  for (int i; i < 60; i++){
    delay(1000);
  }
}