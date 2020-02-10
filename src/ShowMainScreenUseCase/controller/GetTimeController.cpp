#include "GetTimeController.h"

GetTimeController::GetTimeController(){ }

String GetTimeController::getCurrentTime() {
  String currentTime = formatDigit(String(hour())) + ":" + formatDigit(String(minute()));
  return currentTime;
}

String GetTimeController::getCurrentDate() {
  String currentDate = formatDigit(String(day())) + " " + monthShortStr(month()) + " " + year();
  return currentDate;
}

String GetTimeController::formatDigit(String digit) {
  if(digit.length() == 1) {
    String formatedDigit = "0" + digit;
    return formatedDigit;
   }
   return digit;
}
