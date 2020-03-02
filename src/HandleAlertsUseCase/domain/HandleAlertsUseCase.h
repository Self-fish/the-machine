#ifndef HandleAlertsUseCase_h
#define HandleAlertsUseCase_h

#include "../controller/AlertsScreenController.h"


class HandleAlertsUseCase {

public:
  HandleAlertsUseCase(AlertsScreenController* sController);
  void showAlert(char* alert);

private:
  AlertsScreenController* screenContrller;
  void freeResources();
};


#endif
