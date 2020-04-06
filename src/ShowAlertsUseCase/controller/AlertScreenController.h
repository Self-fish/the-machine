#ifndef AlertScreenController_h
#define AlertScreenController_h

#include "../../core/controller/LCDController.h"
#include "../../core/controller/CurrentStatusController.h"

class AlertScreenController {

public:
  AlertScreenController(LCDController* lController, CurrentStatusController*
    sController);
  void printAlert(char* alertText, String alertDate);

private:
  LCDController* lcdController;
  CurrentStatusController* statusController;
  void freeResources();

};


#endif
