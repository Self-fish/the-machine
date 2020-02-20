#include "HandleLightsAction.h"

HandleLightsAction::HandleLightsAction(LightsController* c,
  UsbController* uController) : Action(uController){
  controller = c;
}

void HandleLightsAction::executeAction(char* inputString) {
  if(strstr(inputString, LIGHT_ON_ACTION) != NULL) {
    controller->turnOnLights();
    usbController->sendString(OK);
  } else if(strstr(inputString, LIGHT_OFF_ACTION) != NULL) {
    controller->turnOffLights();
    usbController->sendString(OK);
  } else if (strstr(inputString, LIGHT_GET_ACTION) != NULL) {
    if(controller->lightsStatus() == 0) {
      usbController->sendString(ON);
    } else {
      usbController->sendString(OFF);
    }
  }
}
