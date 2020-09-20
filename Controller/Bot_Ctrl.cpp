
#include "Arduino.h"
#include "definitions.h"
#include "Bot_Ctrl.h"


void botCtrl::init(){
  for(uint8_t i = 0; i < TOTALBOTS; i++){
    bots[i].botID = i;
    bots[i].dir = 0;
    bots[i].standby = 1;
    bots[i].moving = 0;
    bots[i].command = 0;
  }
}
