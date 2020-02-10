#ifndef TimeController_h
#define TimeController_h

#include "Arduino.h"
#include "../../../lib/TimeLib/TimeLib.h"

class TimeController {

public:
  TimeController();
  void configureTime(long currentTimeInMilis);

private:

};


#endif
