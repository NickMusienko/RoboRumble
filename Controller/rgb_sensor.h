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
    
  private:
    Adafruit_TCS34725 _tcs;
};



#endif
