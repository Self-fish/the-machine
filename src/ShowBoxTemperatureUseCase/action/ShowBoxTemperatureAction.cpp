#include "ShowBoxTemperatureAction.h"

ShowBoxTemperatureAction::ShowBoxTemperatureAction(ShowBoxTemperatureUseCase* tUseCase,
    ShowMainScreenUseCase* mUseCase,
    UsbController* uController) : Action(uController){
  temperatureUseCase = tUseCase;
  mainScreenUseCase = mUseCase;
}

void ShowBoxTemperatureAction::executeAction(char* inputString) {
    mainScreenUseCase->showScreen();
    temperatureUseCase->printBoxTemperature();
    usbController->sendString(OK);
    freeResources();
}

void ShowBoxTemperatureAction::freeResources() {
  free(temperatureUseCase);
  free(mainScreenUseCase);
  free(usbController);
}
