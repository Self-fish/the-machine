#ifndef AlertsScreenController_h
#define AlertsScreenController_h

#include "Arduino.h"
#include "../../core/controller/LCDController.h"


class AlertsScreenController {

public:
  AlertsScreenController(LCDController* controller);
  void configureSpecialCharacters();
  void createScreen();
  void printAlert(String alert);
  void freeResources();

private:
  LCDController* lcdController;
  byte anchor0[8] = {B00000,B00000,B00100,B01110,B01010,B01110,B00100,B00100};
  byte anchor1[8] = {B00000,B00000,B11111,B00000,B00000,B00000,B00000,B00000};
  byte anchor2[8] = {B00100,B00100,B11111,B00100,B00100,B00100,B00100,B00100};
  byte anchor3[8] = {B00100,B00100,B00100,B00100,B00100,B00100,B00100,B11111};
  byte anchor4[8] = {B00000,B00000,B11110,B11100,B11100,B10010,B00001,B00000};
  byte anchor5[8] = {B00000,B00000,B01111,B00111,B00111,B01001,B10000,B00000};
  void paintSignal(int column, int row);

};


#endif
