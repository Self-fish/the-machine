#include "ShowWaterTemperatureAction.h"

ShowWaterTemperatureAction::ShowWaterTemperatureAction(ShowWaterTemperatureUseCase* tUseCase,
    ShowMainScreenUseCase* mUseCase,
    UsbController* uController) : Action(uController){
  temperatureUseCase = tUseCase;
  mainScreenUseCase = mUseCase;
}

void ShowWaterTemperatureAction::executeAction(char* inputString) {
    mainScreenUseCase->showScreen();
    temperatureUseCase->printWaterTemperature();
    usbController->sendString(OK);
}
