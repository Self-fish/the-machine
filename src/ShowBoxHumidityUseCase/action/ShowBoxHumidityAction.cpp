#include "ShowBoxHumidityAction.h"

ShowBoxHumidityAction::ShowBoxHumidityAction(ShowBoxHumidityUseCase* hUseCase,
  ShowMainScreenUseCase* mUseCase,
  UsbController* uController) : Action(uController){
  humidityUseCase = hUseCase;
  mainScreenUseCase = mUseCase;
}

void ShowBoxHumidityAction::executeAction(char* inputString) {
    mainScreenUseCase->showScreen();
    humidityUseCase->printHumidity();
    usbController->sendString(OK);
}
