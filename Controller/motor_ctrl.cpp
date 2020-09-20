
#include "Arduino.h"

#include "definitions.h"
#include "motor_ctrl.h"

void motorCtrl::init()
{
  pinMode(PIN_M1A, OUTPUT);
  pinMode(PIN_M2A, OUTPUT);
  pinMode(PIN_M1B, OUTPUT);
  pinMode(PIN_M2B, OUTPUT);

  digitalWrite(PIN_M1A, LOW);
  digitalWrite(PIN_M1B, LOW);
  digitalWrite(PIN_M2A, LOW);
  digitalWrite(PIN_M2B, LOW);

  stateM1 = STOP;
  stateM2 = STOP;
  command = STOP;

  if (Serial) Serial.println("Motors initalized successfully.");
}

void motorCtrl::_drive(uint8_t m, uint8_t dir)
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

void motorCtrl::drive(uint8_t dir)
{
  command = dir;
  switch (dir) {
    case FORWARD:
      stateM1 = FORWARD;
      stateM2 = FORWARD;
      break;
    case BACKWARD:
      stateM1 = BACKWARD;
      stateM2 = BACKWARD;
      break;
    case TURN_L:
      stateM1 = FORWARD;
      stateM2 = BACKWARD;
      break;
    case TURN_R:
      stateM1 = BACKWARD;
      stateM2 = FORWARD;
      break;
    case STOP:
      stateM1 = STOP;
      stateM2 = STOP;
      break;
    default:
      break;
  }

  motorCtrl::_drive(M1, stateM1);
  motorCtrl::_drive(M2, stateM2);
}

void motorCtrl::driveT(uint8_t dir, unsigned long t)
{
  motorCtrl::drive(dir);
  delay(t);
  motorCtrl::drive(STOP);
}
