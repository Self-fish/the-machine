#ifndef CurrentStatusController_h
#define CurrentStatusController_h

#include "Arduino.h"

class CurrentStatusController {

public:
  CurrentStatusController();
  bool isMainScreenActive();
  bool isAlertSreenActive();
  void setIsMainScreenActive(bool isActive);
  void setIsAlertScreenActive(bool isActive);

private:
  bool mainScreenActive;
  bool alertScreenActive;

};


#endif
