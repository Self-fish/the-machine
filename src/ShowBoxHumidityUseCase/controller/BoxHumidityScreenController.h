#ifndef BoxHumidityScreenController_h
#define BoxHumidityScreenController_h

#include "Arduino.h"
#include "../../core/controller/LCDController.h"


class BoxHumidityScreenController {

public:
  BoxHumidityScreenController(LCDController* controller);
  void printBoxHumidity(char* humidity);
  void configureSpecialCharacters();

private:
  LCDController* lcdController;
  byte waterDrop[8] = {B00100,B00100,B01010,B01010,B10001,B10001,B10001,B01110};
};


#endif
