#ifndef CurrentStatusController_h
#define CurrentStatusController_h

#include "Arduino.h"


class CurrentStatusController {

public:
  CurrentStatusController();
  bool isMainScreenActive();
  void setIsMainScreenActive(bool isActive);

private:
  bool mainScreenActive;

};


#endif
