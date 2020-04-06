#ifndef HandleAlertUseCase_h
#define HandleAlertUseCase_h

#include "../../core/controller/AlertsController.h"

class StoreAlertUseCase {

public:

  StoreAlertUseCase(AlertsController* aController);
  void storeAlert(char* alertText);


private:
  AlertsController* alertsController;

};

#endif
