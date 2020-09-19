
uint8_t bot_tar = 8;

#include "definitions.h";
#include "now_net.h";
#include "Bot_Ctrl.h";
botCtrl bots[TOTALBOTS];

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
    esp_now_msg_t msg;
    msg = create_msg(bot_tar, bots[bot_tar]);
    send_msg(&msg);
    
  }
  
  for(uint8_t i=0; i<5;i++){digitalWrite(LED[i],LOW);}
  if(bot_tar < 5){digitalWrite(LED[bot_tar+1], HIGH);}
  else{digitalWrite(LED[0],HIGH);}

  delay(10);
}
