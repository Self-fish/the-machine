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
  void createScreen(String hour, String date);
  void printAlert(char* alert);
  void hideAlert();
  void finishAlert();
  void freeResources();

private:
  LCDController* lcdController;
  CurrentStatusController* currentStatusController;
  byte warning0[8] = {B00000,B00100,B00100,B01110,B01110,B11111,B11111,B10001};
  byte warning1[8] = {B00011,B00011,B00111,B00111,B01111,B01111,B11111,B11111};
  byte warning2[8] = {B10001,B10001,B10001,B10001,B10001,B10001,B10001,B10001};
  byte warning3[8] = {B11000,B11000,B11100,B11100,B11110,B11110,B11111,B11111};
  byte warning4[8] = {B00000,B00001,B00001,B00011,B00011,B00111,B00111,B00000};
  byte warning5[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B00000};
  byte warning6[8] = {B10001,B10001,B11111,B10001,B10001,B10001,B11111,B00000};
  byte warning7[8] = {B00000,B10000,B10000,B11000,B11000,B11100,B11100,B00000};
  void paintSignal(int column, int row);

};


#endif
