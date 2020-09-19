#include "definitions.h"
#include "Adafruit_TCS34725.h"
#include "motor_ctrl.h"
#include "rgb_sensor.h"

color currColor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initMotors();
  initRGB;
}

void loop() {
  // put your main code here, to run repeatedly:
  int testState = 0;
  if (testState == 0)
  {
    driveMotors(FORWARD, FORWARD);
    delay(1000);
    driveMotors(STOP, STOP);
    delay(1000);
    driveMotors(BACKWARD, BACKWARD);
    delay(1000);
    driveMotors(STOP, STOP);
    delay(1000);
  }
  else
  {
    testRGB();
    delay(1000);
  }
}
