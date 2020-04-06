#ifndef ShowAlertsUseCase_h
#define ShowAlertsUseCase_h

#include "../controller/AlertTimeController.h"
#include "../controller/AlertScreenController.h"
#include "../../core/controller/AlertsController.h"

class ShowAlertsUseCase {

public:
  ShowAlertsUseCase(AlertTimeController* tController,
    AlertScreenController* sController, AlertsController* aController);
  void showAlerts();

private:
  AlertTimeController* timeController;
  AlertScreenController* screenController;
  AlertsController* alertsController;
  void freeResources();
};


#endif
