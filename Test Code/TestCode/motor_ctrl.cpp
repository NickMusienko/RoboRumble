#include "motor_ctrl.h"

void initMotors()
{
  pinMode(PIN_M1A, OUTPUT);
  pinMode(PIN_M2A, OUTPUT);
  pinMode(PIN_M1B, OUTPUT);
  pinMode(PIN_M2B, OUTPUT);

  digitalWrite(PIN_M1A, LOW);
  digitalWrite(PIN_M1B, LOW);
  digitalWrite(PIN_M2A, LOW);
  digitalWrite(PIN_M2B, LOW);

  if (Serial) Serial.println("Motors initalized successfully.");
}

void driveMotor(uint8_t m, uint8_t dir)
{
  if (m == M1)
  {
    switch (dir)
    {
      case FORWARD:
        digitalWrite(PIN_M1A, HIGH);
        digitalWrite(PIN_M1B, LOW);
        break;
      case BACKWARD:
        digitalWrite(PIN_M1A, LOW);
        digitalWrite(PIN_M1B, HIGH);
        break;
      case STOP:
        digitalWrite(PIN_M1A, LOW);
        digitalWrite(PIN_M1B, LOW);
        break;
      default:
        break;
    }
  }
  else if (m == M2)
    switch (dir)
    {
      case FORWARD:
        digitalWrite(PIN_M2A, HIGH);
        digitalWrite(PIN_M2B, LOW);
        break;
      case BACKWARD:
        digitalWrite(PIN_M2A, LOW);
        digitalWrite(PIN_M2B, HIGH);
        break;
      case STOP:
        digitalWrite(PIN_M2A, LOW);
        digitalWrite(PIN_M2B, LOW);
        break;
      default:
        break;
    }
}

void driveMotors(uint8_t dir1, uint8_t dir2)
{
  driveMotor(M1, dir1);
  driveMotor(M2, dir2);
}
