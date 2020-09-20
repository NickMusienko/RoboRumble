#ifndef DEFINITIONS_H
#define DEFINITIONS_H

//#define MASTER
#ifndef MASTER
#define BOT
#define BOT_ID 0

// esp32 pin definitions
#define PIN_M1A   16
#define PIN_M1B   17
#define PIN_M2A   18
#define PIN_M2B   19

#define PIN_SDA   21
#define PIN_SCL   22
#define PIN_LED   23 // don't use yet pls

// motor commands
#define M1    0
#define M2    1

#define colorA 0
#define colorB 1
#define colorC 2
#define colorD 3
#define colorE 4
#define colorF 5
#define colorG 6
#define colorH 7
#define colorI 8

#endif

#define WIFI_CHANNEL 1
#define TOTALBOTS 4

#define STOP      0
#define FORWARD   1
#define BACKWARD  2
#define TURN_L    3
#define TURN_R    4

#endif
