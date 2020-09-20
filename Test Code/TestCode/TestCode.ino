#include "definitions.h"
#include "Adafruit_TCS34725.h"
#include "motor_ctrl.h"
#include "rgb_sensor.h"

motorCtrl mC;
SensorRGB rgb;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mC.init();
  rgb.init();
  rgb.setLED(HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int testState = 1;
  if (testState == 0)
  {
    mC.driveT(FORWARD, 1000);
    mC.driveT(BACKWARD, 1000);
    mC.driveT(TURN_L, 1000);
    mC.driveT(TURN_R, 1000);
  }
  else
  {
    rgb.test();
    delay(50);
  }
}
