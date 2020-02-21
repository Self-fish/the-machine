#ifndef WelcomeScreenController_h
#define WelcomeScreenController_h

#include "Arduino.h"
#include "../../core/controller/LCDController.h"
#include "../../core/controller/CurrentStatusController.h"


class WelcomeScreenController {

public:
  WelcomeScreenController(LCDController* controller,
    CurrentStatusController* statusController);
  void configureSpecialCharacters();
  void printWelcomeMessage();
  void printLoading();

private:
  LCDController* lcdController;
  CurrentStatusController* currentStatusController;
  byte loadingBar0[8] = {B01111,B11000,B10011,B10111,B10111,B10011,B11000,B01111};
  byte loadingBar1[8] = {B11111,B00000,B11011,B11011,B11011,B11011,B00000,B11111};
  byte loadingBar2[8] = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B11111};
  byte loadingBar3[8] = {B11110,B00011,B00001,B00001,B00001,B00001,B00011,B11110};
  byte loadingBar4[8] = {B11110,B00011,B11001,B11101,B11101,B11001,B00011,B11110};
  byte fish1[8] = {B00000,B00000,B00111,B01111,B11011,B01111,B00111,B00000};
  byte fish2[8] = {B00000,B00001,B10001,B11011,B11111,B11011,B10001,B00001};
  void paintFish(int column, int row);
  void paintFishBank(int startingColumn);
  void createLoadingAnimation();
  void paintLoadingBar(int percentaje);
  void freeResources();
};


#endif
