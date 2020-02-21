#ifndef WaterTemperatureScreenController_h
#define WaterTemperatureScreenController_h

#include "Arduino.h"
#include "../../core/controller/LCDController.h"


class WaterTemperatureScreenController {

public:
  WaterTemperatureScreenController(LCDController* controller);
  void printWaterTemperature(char* temperature);
  void configureSpecialCharacters();

private:
  LCDController* lcdController;
  byte water1[8] = {B01001,B01001,B10010,B10010,B01001,B00000,B11111,B11111};
  void freeResources();
};


#endif
