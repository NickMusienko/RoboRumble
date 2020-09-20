
uint8_t bot_tar = 8;
uint8_t newCommand = 0;
#include "definitions.h";

  #include "now_net.h";
  #include "Bot_Ctrl.h";
  botCtrl bots[TOTALBOTS];

#ifdef MASTER 
  #include "Keypad_Ctrl.h"
  #include <Keypad.h>
  buttonID keypadData;
  Keypad customKeypad = Keypad(makeKeymap(hexaNums), rowPins, colPins, ROWS, COLS);

#endif

#ifndef MASTER
  #include "Adafruit_TCS34725.h"
  #include "motor_ctrl.h"
  #include "rgb_sensor.h"

  motorCtrl mC;
  SensorRGB rgb;
#endif

void setup() {
  Serial.begin(115200);

  #ifdef MASTER
  for(int i=0; i<5; i++){
    pinMode(LED[i], OUTPUT);
    bots[i].init();
  };
  #endif
  #ifndef MASTER
    mC.init();
    rgb.init();
  #endif

  network_setup();
}

void loop() {

  #ifdef MASTER
    uint8_t customKey = customKeypad.getKey();
  
    if(customKey){
      //Serial.print(customKey);
      keypadData = keypadRead(customKey, keypadData);
      bot_tar = keypadData.botID;
      bots[bot_tar].command = keypadData.commandID;
      esp_now_msg_t msg;
      msg = create_msg(bot_tar, bots[bot_tar]);
      send_msg(&msg); 
    }
  
  for(uint8_t i=0; i<5;i++){digitalWrite(LED[i],LOW);}
  digitalWrite(LED[0],HIGH);
  if(bot_tar < 5){digitalWrite(LED[bot_tar+1], HIGH);digitalWrite(LED[0],LOW);}
  
  #endif

  #ifndef MASTER
    while(bots[BOT_ID].standby != 1){
      Serial.print("Executing Command: ");
      Serial.println(bots[BOT_ID].command);
      delay(1000);
      Serial.println("waiting...");
      delay(1000);
      Serial.println("done!");
      bots[BOT_ID].standby = 1;
      bots[BOT_ID].command = 0;
      esp_now_msg_t msg;
      msg = create_msg(BOT_ID, bots[BOT_ID]);
      send_msg(&msg);
    }
    
 
  #endif
  
  //Serial.println(bot_tar);
  delay(10);
}
