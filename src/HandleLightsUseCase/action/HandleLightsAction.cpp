#include "HandleLightsAction.h"

HandleLightsAction::HandleLightsAction(RelayController* c,
  UsbController* uController) : Action(uController){
  controller = c;
}

void HandleLightsAction::executeAction(char* inputString) {
  if(strstr(inputString, LIGHT_ON_ACTION) != NULL) {
    controller->turnOn();
    usbController->sendString(OK);
    freeResources();
  } else if(strstr(inputString, LIGHT_OFF_ACTION) != NULL) {
    controller->turnOff();
    usbController->sendString(OK);
    freeResources();
  } else if (strstr(inputString, LIGHT_GET_ACTION) != NULL) {
    if(controller->getValue() == 0) {
      usbController->sendString(ON);
    } else {
      usbController->sendString(OFF);
    }
    freeResources();
  }
}

void HandleLightsAction::freeResources() {
  free(controller);
  free(usbController);
}
