
uint8_t pos[4][8] = {{0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0}
                    };

uint8_t bot_tar = 8;

#include "definitions.h";
#include "now_net.h";

#include "Keypad_Ctrl.h"
#include <Keypad.h>

Keypad customKeypad = Keypad(makeKeymap(hexaNums), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  for(int i=0; i<5; i++){pinMode(LED[i], OUTPUT);};
}

void loop() {
  uint8_t customKey = customKeypad.getKey();

  if(customKey){
    Serial.print(customKey);
    bot_tar = selectBot(customKey, bot_tar);
    for(uint8_t i=0; i<5;i++){digitalWrite(LED[i],LOW);}
  }

  if(bot_tar < 4){digitalWrite(LED[bot_tar+1], HIGH);}
  else{digitalWrite(LED[0],HIGH);}

  delay(10);
}
