
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


  #include "Adafruit_TCS34725.h"
  #include "motor_ctrl.h"
  #include "rgb_sensor.h"

  motorCtrl mC;
  SensorRGB rgb;


void setup() {
  Serial.begin(115200);

  #ifdef MASTER
  for(int i=0; i<5; i++){
    pinMode(LED[i], OUTPUT);
    bots[i].init();
  };
  #endif
  #ifndef MASTER
    bots[BOT_ID].init();
    mC.init();
    rgb.init();
  #endif

  network_setup();
}

void loop() {

  #ifdef MASTER
//    boolean standby = true;
//    for( int i = 0; i < TOTALBOTS; i++){
//      if(bots[i].standby != 1){standby = false; break;}
//    }
//
//    if(standby){
    
    if(Serial.available() > 0){
      String newString = Serial.readString();
      if(newString == "f"){ newCommand = 1;}  
      else if(newString == "r"){ newCommand = 2;}
      else if(newString == "b"){ newCommand = 3;}
      else if(newString == "l"){ newCommand = 4;}
      else if(newString == "2"){ bot_tar = 2;}
      

      if(newCommand > 0){
        Serial.println(newCommand);
        bots[bot_tar].command = newCommand;
        esp_now_msg_t msg;
        msg = create_msg(bot_tar, bots[bot_tar]);
        send_msg(&msg);
      }
    }
      
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
//    }
  #endif

  #ifndef MASTER
    //rgb.test();

    
    while(bots[BOT_ID].standby != 1){
      uint8_t startingColor = rgb.getColor();
      mC.driveT(bots[BOT_ID].command, 5000);
      Serial.print("Executing Command: ");
      Serial.println(bots[BOT_ID].command);
      int8_t endColor = rgb.getColor();
      int8_t chgX, chgY;
      if(startingColor != endColor){
        int8_t change;
        change = rgb.changePos(startingColor,endColor);
        if(change >= 3){chgY = change - 4; chgX = 0;}
        else{chgX = change - 1; chgY = 0;};
        
        bots[BOT_ID].posX += chgX;
        bots[BOT_ID].posY += chgY;
      }
        
      bots[BOT_ID].standby = 1;
      bots[BOT_ID].command = 0;
    }
  
    esp_now_msg_t msg;
    msg = create_msg(BOT_ID, bots[BOT_ID]);
    send_msg(&msg);
    
  #endif
  
  //Serial.println(bot_tar);
  delay(10);
}
