#ifndef AlertsScreenController_h
#define AlertsScreenController_h

#include "Arduino.h"
#include "../../core/controller/LCDController.h"
#include "../../core/controller/CurrentStatusController.h"


class AlertsScreenController {

public:
  AlertsScreenController(LCDController* controller,
    CurrentStatusController* statusC);
  void configureSpecialCharacters();
  void createScreen();
  void printAlert(String alert);
  void freeResources();

private:
  LCDController* lcdController;
  CurrentStatusController* currentStatusController;
  byte warning0[8] = {B00100,B00100,B01010,B01010,B10001,B10001,B00000,B00000};
  byte warning1[8] = {B00001,B00001,B00010,B00010,B00100,B00100,B01000,B10000};
  byte warning2[8] = {B00100,B00100,B00100,B00100,B00100,B00100,B00100,B00100};
  byte warning3[8] = {B10000,B10000,B01000,B01000,B00100,B00100,B00010,B00001};
  byte warning4[8] = {B00001,B00010,B00010,B00100,B00100,B01000,B01000,B01111};
  byte warning5[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B11111};
  byte warning6[8] = {B00100,B00100,B00100,B00100,B00000,B00100,B00000,B11111};
  byte warning7[8] = {B10000,B01000,B01000,B00100,B00100,B00010,B00010,B11110};
  void paintSignal(int column, int row);

};


#endif
