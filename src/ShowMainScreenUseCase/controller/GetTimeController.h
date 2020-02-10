#ifndef GetTimeController_h
#define GetTimeController_h

#include "Arduino.h"
#include "../../../lib/TimeLib/TimeLib.h"


class GetTimeController {

public:
  GetTimeController();
  String getCurrentTime();
  String getCurrentDate();

private:
  String formatDigit(String digit);
};


#endif
