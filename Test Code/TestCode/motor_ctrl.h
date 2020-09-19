#ifndef MOTOR_CTRL_H
#define MOTOR_CTRL_H

#include "definitions.h"

void initMotors();
void driveMotor(uint8_t m, uint8_t dir);
void driveMotors(uint8_t dir1, uint8_t dir2);


#endif
