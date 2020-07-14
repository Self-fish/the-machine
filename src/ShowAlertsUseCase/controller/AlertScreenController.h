#ifndef AlertScreenController_h
#define AlertScreenController_h

#include "../../core/controller/LCDController.h"
#include "../../core/controller/CurrentStatusController.h"

class AlertScreenController {

public:
  AlertScreenController(LCDController* lController, CurrentStatusController*
    sController);
  void printAlert(char* alertText, String alertDate, bool isLastAlert);
  void printCloseMenu();
  void freeResources();

private:
  LCDController* lcdController;
  CurrentStatusController* statusController;
  int calculateFirstCharacterScreenPisition(char* alertText);


};


#endif
