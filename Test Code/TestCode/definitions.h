// NEEDS ADAFRUIT_TCS34725 LIBRARY TO FUNCTION
// FIND IT IN THE LIBRARY MANAGER

// blanket library definitions
#include <stdint.h>
#include <Arduino.h>


// esp32 pin definitions
#define PIN_M1A   16
#define PIN_M1B   17
#define PIN_M2A   18
#define PIN_M2B   19

#define PIN_SDA   21
#define PIN_SCL   22

// motor commands
#define M1    0
#define M2    1

#define FORWARD   0
#define BACKWARD  1
#define STOP      2