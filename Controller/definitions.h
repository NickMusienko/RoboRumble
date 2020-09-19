#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define MASTER
#ifndef MASTER
#define Slave
#define Bot_ID 0
#endif

#define WIFI_CHANNEL 1


const uint8_t ROWS = 4;
const uint8_t COLS = 4;
uint8_t rowPins[ROWS] = {19, 18, 5, 17};
uint8_t colPins[COLS] = {16, 4, 0, 2};

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

uint8_t hexaNums[ROWS][COLS] = {
  {0,1,2,3},
  {4,5,6,7},
  {8,9,10,11},
  {12,13,14,15}
};

uint8_t LED[5] = {32, 33, 25, 26, 27};

#endif
