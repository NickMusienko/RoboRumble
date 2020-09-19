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

extern uint8_t LED[5] = {32, 33, 25, 26, 27};

uint8_t selectBot(uint8_t button, uint8_t currentBot){
  uint8_t newBot = currentBot;
  switch (button){
      case 3:
        newBot = 0;
        break;
      case 7:
        newBot = 1;
        break;
      case 11:
        newBot = 2;
        break;
      case 15:
        newBot = 3;
        break;
      case 12:
        newBot = 8;
      default:
        newBot = currentBot;
        break;
    }
  return newBot;
}
