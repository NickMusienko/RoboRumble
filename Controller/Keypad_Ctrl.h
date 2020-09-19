const uint8_t ROWS = 4;
const uint8_t COLS = 4;
extern uint8_t rowPins[ROWS] = {19, 18, 5, 17};
extern uint8_t colPins[COLS] = {16, 4, 0, 2};

extern char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

extern uint8_t hexaNums[ROWS][COLS] = {
  {0,1,2,3},
  {4,5,6,7},
  {8,9,10,11},
  {12,13,14,15}
};

typedef struct buttonID{
  uint8_t botID = 8;
  uint8_t commandID = 0;
};

extern uint8_t LED[5] = {32, 33, 25, 26, 27};

buttonID keypadRead(uint8_t button, buttonID oldInput){
  uint8_t newBot = oldInput.botID;
  buttonID newInput;
  switch (button){
      case 3:                       //"A" Button
        newBot = 0;
        newCommand = 0;
        break;
      case 7:                       //"B" Button
        newBot = 1;
        newCommand = 0;
        break;
      case 11:                      //"C" Button
        newBot = 2;
        newCommand = 0;
        break;
      case 15:                      //"D" Button
        newBot = 3;
        newCommand = 0;
        break;
      case 12:                      //"*" Button
        newBot = 8;
        newCommand = 0;
        break;
      case 1:                       //"1" Button
        newCommand = 1; //forward      
        break;
      case 4:                       //"4" Button
        newCommand = 4; //turn left
        break;
      case 6:                       //"6" Button
        newCommand = 2; //turn right
        break;
      case 9:                       //"8" Button
        newCommand = 3; //reverse
        break;
      default:                      //default is to return the same botID and stop the bot.
        newBot = oldInput.botID;
        newCommand = 0;
        break;
    }

  newInput.botID = newBot;
  newInput.commandID = newCommand;
  return newInput;
}
