#ifndef ShowAlertsUseCase_h
#define ShowAlertsUseCase_h

#include "../controller/AlertTimeController.h"
#include "../controller/AlertScreenController.h"
#include "../../core/controller/AlertsController.h"
#include "../controller/JoystickController.h"
#include "../../core/controller/CurrentStatusController.h"

class ShowAlertsUseCase {

public:
  ShowAlertsUseCase(AlertTimeController* tController,
    AlertScreenController* sController, AlertsController* aController,
    JoystickController* joystickController,
    CurrentStatusController* currentStatusController);
  void showAlerts();

private:
  AlertTimeController* timeController;
  AlertScreenController* screenController;
  AlertsController* alertsController;
  JoystickController* joystickController;
  CurrentStatusController* currentStatusController;
  void showSpecificAlert(char* alertText, time_t alertsDate, bool isLastAlert);
  void waitUserInteraction();
  void freeResources();
};


#endif
