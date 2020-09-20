#include "rgb_sensor.h"

void SensorRGB::init() {
  _tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X); 
  pinMode(PIN_LED, OUTPUT);
  
  
  if (_tcs.begin()) {
    if (Serial) Serial.println("Found sensor");
  }
  else {
    if (Serial) Serial.println("No sensor found. Check your wiring.");
  }
  r = 0;
  g = 0;
  b = 0;
  c = 0;
  led = false;
  
}

void SensorRGB::update() {
  _tcs.getRawData(&r, &g, &b, &c);
}

void SensorRGB::test() {
  if (Serial) {
    SensorRGB::update();
    Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
    Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
    Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
    Serial.print("C: "); Serial.print(c, DEC); Serial.println(" ");
  }
}

void SensorRGB::setLED(uint8_t state) {
  digitalWrite(PIN_LED, state);
  led = (bool)state;
}
