#ifndef HandleAlertsUseCase_h
#define HandleAlertsUseCase_h

#include "../controller/AlertsScreenController.h"
#include "../controller/AlertMenuScreenController.h"
#include "../controller/JoystickController.h"
#include "../../ShowMainScreenUseCase/controller/GetTimeController.h"
#include "../../../lib/MemoryFree/MemoryFree.h"

#define DONE 0
#define LATER 1

class HandleAlertsUseCase {

public:
  HandleAlertsUseCase(AlertsScreenController* sController,
    GetTimeController* tController, JoystickController* jController,
    AlertMenuScreenController* mController);
  int showAlert(char* alert);

private:
  AlertsScreenController* screenContrller;
  AlertMenuScreenController* menuController;
  JoystickController* joystickController;
  GetTimeController* timeController;
  void blinkAlert(char* alert, boolean alertVisible,
      long startingTime, boolean shouldBlink);
  void handleMenu();
  void freeResources();
};


#endif
