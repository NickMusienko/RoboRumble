#ifndef BOT_CTRL_H
#define BOT_CTRL_H

class botCtrl{
  public:
    uint8_t botID;
    uint8_t posX;
    uint8_t posY;
    uint8_t dir;
    boolean standby;
    boolean moving;
    uint8_t command;

    static void init();
    static void setup();
    
};

extern botCtrl bots[TOTALBOTS];
#endif
