#include "HandleAlertsUseCase.h"

HandleAlertsUseCase::HandleAlertsUseCase(AlertsScreenController* sController,
    GetTimeController* tController, JoystickController* jController,
    AlertMenuScreenController* mController) {
  screenContrller = sController;
  timeController = tController;
  joystickController = jController;
  menuController = mController;
}

int HandleAlertsUseCase::showAlert(char *alert) {
  int result = DONE;
  screenContrller->configureSpecialCharacters();
  screenContrller->createScreen(timeController->getCurrentTime(),
    timeController->getCurrentDate());
  screenContrller->printAlert(alert);
  blinkAlert(alert, true, millis(), true);
  //menuController->showMenu();
  //delay(500);
  //handleMenu();
  menuController->closeMenu();
  //if(menuController->getMenuPosition() == 1) {
  //  result = LATER;
  //}
  freeResources();
  return result;
}

void HandleAlertsUseCase::blinkAlert(char* alert, boolean alertVisible,
    long startingTime, boolean shouldBlink) {

  if(joystickController->wasButtonPressed()) {
    shouldBlink = false;
  }
  if(shouldBlink) {
    if(alertVisible && millis() - startingTime > 1000) {
      screenContrller->hideAlert();
      startingTime = millis();
      alertVisible = false;
    } else if(!alertVisible && millis() - startingTime > 500) {
      screenContrller->printAlert(alert);
      alertVisible = true;
      startingTime = millis();
    }
    blinkAlert(alert, alertVisible, startingTime, shouldBlink);
  } else {
    screenContrller->finishAlert();
  }
}

void HandleAlertsUseCase::handleMenu() {
  boolean selected = false;
  while(!selected) {
    if(joystickController->readX() == UP) {
      menuController->selectFirst();
    } else if (joystickController->readX() == DOWN) {
      menuController->selectSecond();
    }
    if(joystickController->wasButtonPressed()) {
      selected = true;
    }
  }
}

void HandleAlertsUseCase::freeResources() {
  free(screenContrller);
  free(menuController);
  free(timeController);
  free(joystickController);
}
