#ifndef RGB_SENSOR_H
#define RGB_SENSOR_H

#include <Wire.h>
#include "Adafruit_TCS34725.h"

#include "definitions.h"

class SensorRGB{
  public:
    uint16_t r;
    uint16_t g;
    uint16_t b;
    uint16_t c;
    bool led;

    void init();
    void update();
    void setLED(uint8_t state);
    void test();
    uint8_t getColor();
    uint8_t mapColor();
    int8_t changePos(uint8_t startCol, uint8_t endCol);
  private:
    Adafruit_TCS34725 _tcs;
};

#define LEFT 0
#define RIGHT 2
#define UP 5
#define DOWN 3

#endif
