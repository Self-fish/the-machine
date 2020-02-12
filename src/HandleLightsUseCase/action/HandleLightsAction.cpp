#include "HandleLightsAction.h"

HandleLightsAction::HandleLightsAction(HandleLightsUseCase* lUseCase,
UsbController* uController) : Action(uController){
  useCase = lUseCase;
}

void HandleLightsAction::executeAction(char* inputString) {
  if(strstr(inputString, LIGHT_ON_ACTION) != NULL) {
    useCase->turnOnLights();
    usbController->sendString(OK);
  } else if(strstr(inputString, LIGHT_OFF_ACTION) != NULL) {
    useCase->turnOffLights();
    usbController->sendString(OK);
  } else if (strstr(inputString, LIGHT_GET_ACTION) != NULL) {
    if(useCase->isLightOn()) {
      usbController->sendString(ON);
    } else {
      usbController->sendString(OFF);
    }
  }
}
