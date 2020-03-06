#ifndef AlertMenuScreenController_h
#define AlertMenuScreenController_h

#include "Arduino.h"
#include "../../core/controller/LCDController.h"

class AlertMenuScreenController {

public:
  AlertMenuScreenController(LCDController* lController);
  void showMenu();
  void selectFirst();
  void selectSecond();
  void closeMenu();
  int getMenuPosition();

private:

  LCDController* lcdController;
  int menuPosition;
  void freeResources();

};

#endif
