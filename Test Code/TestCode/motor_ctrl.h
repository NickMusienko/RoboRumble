#ifndef MOTOR_CTRL_H
#define MOTOR_CTRL_H

#include "definitions.h"

class motorCtrl {
  public:
    uint8_t stateM1;
    uint8_t stateM2;
    uint8_t command;

    void init();
    void drive(uint8_t dir);
    void driveT(uint8_t dir, unsigned long t);

  private:
    void _drive(uint8_t m, uint8_t dir);
};

#endif
