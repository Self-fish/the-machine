#ifndef BoxTemperatureScreenController_h
#define BoxTemperatureScreenController_h

#include "Arduino.h"
#include "../../core/controller/LCDController.h"


class BoxTemperatureScreenController {

public:
  BoxTemperatureScreenController(LCDController* controller);
  void printBoxTemperature(char* temperature);
  void configureSpecialCharacters();

private:
  LCDController* lcdController;
  byte fire[8] = {B00100,B01010,B01010,B01110,B01110,B11111,B11111,B01110};
  void freeResources();
};


#endif
