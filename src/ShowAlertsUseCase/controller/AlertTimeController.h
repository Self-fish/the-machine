#ifndef AlertTimeController_h
#define AlertTimeController_h

#include "../../../lib/TimeLib/TimeLib.h"
#include "Arduino.h"

class AlertTimeController {

public:
  AlertTimeController();
  String getAlertTime(time_t alertTime);

private:
  String formatDigit(String digit);
};

#endif
