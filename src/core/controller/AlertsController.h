#ifndef AlertsController_h
#define AlertsController_h

#include "Arduino.h"
#include "../../../lib/TimeLib/TimeLib.h"

#define ALERTS_SIZE 3

class AlertsController {

public:
  AlertsController();
  void setAlert(char* alert);
  char** getAllAlerts();
  long unsigned int* getAllTimeStamps();
  void cleanAlerts();


private:
  int arrayPos;
  char* alerts[ALERTS_SIZE];
  long unsigned int alertsTimeStamp[ALERTS_SIZE];
  bool alertAlreadyExist(char* alert);
  void addAlert(char* alert);
  void removeOlderAlert();

};


#endif
