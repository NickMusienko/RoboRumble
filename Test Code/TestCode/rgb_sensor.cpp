#include "rgb_sensor.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X); 

void initRGB()
{
  if (tcs.begin()) {
    if (Serial) Serial.println("Found sensor");
  }
  else {
    if (Serial) Serial.println("Did not find sensor");
  }
}

color getRGB()
{
  tcs.getRawData(&curColor.r, &curColor.g, &curColor.b, &curColor.c);
}

void testRGB()
{
  if (Serial) {
    color c = getRGB();
    Serial.print("R: "); Serial.print(c.r, DEC); Serial.print(" ");
    Serial.print("G: "); Serial.print(c.g, DEC); Serial.print(" ");
    Serial.print("B: "); Serial.print(c.b, DEC); Serial.print(" ");
    Serial.print("C: "); Serial.print(c.c, DEC); Serial.print(" ");
  }
}
