#include "rgb_sensor.h"

void SensorRGB::init() {
  _tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X); 
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED,HIGH);
  
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
  led = true;
  
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


uint8_t SensorRGB::mapColor(){
  uint8_t color = 10;                             
                              //rLow, rHigh, gLow, gHigh, bLow, bHigh, cLow, cHigh
  uint16_t thresholds[9][8]{   {   0,  5000,    0,  5000,    0,  5000,    0,  5000}, //colorA purple
                               {   0,  5000,    0,  5000,    0,  5000,    0,  5000}, //colorB pink
                               {   0,  5000,    0,  5000,    0,  5000,    0,  5000}, //colorC yellow
                               {   0,  5000,    0,  5000,    0,  5000,    0,  5000}, //colorD white
                               {   0,  5000,    0,  5000,    0,  5000,    0,  5000}, //colorE green
                               {   0,  5000,    0,  5000,    0,  5000,    0,  5000}, //colorF blue
                               {   0,  5000,    0,  5000,    0,  5000,    0,  5000}, //colorG cyan
                               {   0,  5000,    0,  5000,    0,  5000,    0,  5000}, //colorH red
                               {   0,  5000,    0,  5000,    0,  5000,    0,  5000}  //colorI black
  };

  while (color == 10){
    for(uint8_t i; i < 9; i++){
      if(r >= thresholds[i][0] && r <= thresholds[i][1] && 
         g >= thresholds[i][2] && g <= thresholds[i][3] && 
         b >= thresholds[i][4] && b <= thresholds[i][5] && 
         c >= thresholds[i][6] && c <= thresholds[i][7]){
           color = i;
           break;
         }
    }
    if(color == 10){
      SensorRGB::update();
    }
  }
  return color;
}

uint8_t SensorRGB::getColor(){
  uint8_t color;
  SensorRGB::update();
  color = SensorRGB::mapColor();
  return color;
}

int8_t SensorRGB::changePos(uint8_t startCol, uint8_t endCol){
  int8_t change;
  switch(startCol){
    case 0:
      switch(endCol){
        case 1:
          change = RIGHT;
          break;
        case 3:
          change = DOWN;
          break;
        case 2:
          change = LEFT;
          break;
        case 6:
          change = UP;
          break;
      }
      break;
    case 1:
      switch(endCol){
        case 2:
          change = RIGHT;
          break;
        case 4:
          change = DOWN;
          break;
        case 0:
          change = LEFT;
          break;
        case 7:
          change = UP;
          break;
      }
      break;
    case 2:
      switch(endCol){
        case 0:
          change = RIGHT;
          break;
        case 5:
          change = DOWN;
          break;
        case 1:
          change = LEFT;
          break;
        case 8:
          change = UP;
          break;
      }
      break;
    case 3:
      switch(endCol){
        case 4:
          change = RIGHT;
          break;
        case 6:
          change = DOWN;
          break;
        case 5:
          change = LEFT;
          break;
        case 0:
          change = UP;
          break;
      }
      break;
    case 4:
      switch(endCol){
        case 5:
          change = RIGHT;
          break;
        case 7:
          change = DOWN;
          break;
        case 3:
          change = LEFT;
          break;
        case 1:
          change = UP;
          break;
      }
      break;
    case 5:
      switch(endCol){
        case 3:
          change = RIGHT;
          break;
        case 8:
          change = DOWN;
          break;
        case 4:
          change = LEFT;
          break;
        case 2:
          change = UP;
          break;
      }
      break;
    case 6:
      switch(endCol){
        case 7:
          change = RIGHT;
          break;
        case 0:
          change = DOWN;
          break;
        case 8:
          change = LEFT;
          break;
        case 3:
          change = UP;
          break;
      }
      break;
    case 7:
      switch(endCol){
        case 8:
          change = RIGHT;
          break;
        case 1:
          change = DOWN;
          break;
        case 6:
          change = LEFT;
          break;
        case 4:
          change = UP;
          break;
      }
      break;
    case 8:
      switch(endCol){
        case 6:
          change = RIGHT;
          break;
        case 2:
          change = DOWN;
          break;
        case 7:
          change = LEFT;
          break;
        case 5:
          change = UP;
          break;
      }
      break;

  }
  return change;
}
