#include <Wire.h>
#include "Adafruit_TCS34725.h"

#include "definitions.h"

typedef struct color {
  uint16_t r;
  uint16_t g;
  uint16_t b;
  uint16_t c;
} color;

extern color curColor;

void initRGB();
color getRGB();
void testRGB();
