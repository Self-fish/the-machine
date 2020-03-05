#ifndef HandleAlertsUseCase_h
#define HandleAlertsUseCase_h

#include "../controller/AlertsScreenController.h"
#include "../../ShowMainScreenUseCase/controller/GetTimeController.h"


class HandleAlertsUseCase {

public:
  HandleAlertsUseCase(AlertsScreenController* sController,
    GetTimeController* tController);
  void showAlert(char* alert);

private:
  AlertsScreenController* screenContrller;
  GetTimeController* timeController;
  void freeResources();
};


#endif
