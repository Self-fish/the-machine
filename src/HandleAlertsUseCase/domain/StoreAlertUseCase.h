#ifndef HandleAlertUseCase_h
#define HandleAlertUseCase_h

#include "../../core/controller/AlertsController.h"
#include "../../core/controller/CurrentStatusController.h"

class StoreAlertUseCase {

public:

  StoreAlertUseCase(/*AlertsController* aController,*/
    CurrentStatusController* statusController);
  void storeAlert(char* alertText);


private:
  //AlertsController* alertsController;
  CurrentStatusController* currentStatusController;

};

#endif
