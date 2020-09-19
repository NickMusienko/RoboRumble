


uint8_t pos[4][8] = {{0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0}
                    };

uint8_t bot_tar = 8;

#include "definitions.h";
#include "now_net.h";

#include <Adafruit_Keypad.h>;
#include <Keypad.h>

Keypad customKeypad = Keypad(makeKeymap(hexaNums), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  for(int i=0; i<5; i++){pinMode(LED[i], OUTPUT);};
}

void loop() {
  uint8_t customKey = customKeypad.getKey();

  for(uint8_t i=0; i<5;i++){digitalWrite(LED[i],LOW);}
  if(bot_tar < 4){digitalWrite(LED[bot_tar+1], HIGH);}
  else{digitalWrite(LED[0],HIGH);}

  if(customKey){
    switch (customKey){
      case 3:
        bot_tar = 0;
        break;
      case 7:
        bot_tar = 1;
        break;
      case 11:
        bot_tar = 2;
        break;
      case 15:
        bot_tar = 3;
        break;
      case 12:
        bot_tar = 8;
      default:
        break;
    }
    Serial.println(customKey);
  }


  delay(10);
}
