#include "AlertTimeController.h"

AlertTimeController::AlertTimeController() {}

String AlertTimeController::getAlertTime(time_t alertTime) {
  String currentDate = formatDigit(String(day(alertTime))) + "/" +
    month(alertTime) + "/" + year(alertTime);
  String currentTime = formatDigit(String(hour(alertTime))) + ":" +
    formatDigit(String(minute(alertTime)));
  return currentDate + " at " + currentTime;
}


String AlertTimeController::formatDigit(String digit) {
  if(digit.length() == 1) {
    String formatedDigit = "0" + digit;
    return formatedDigit;
   }
   return digit;
}
