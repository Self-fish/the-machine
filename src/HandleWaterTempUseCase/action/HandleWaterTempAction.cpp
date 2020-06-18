#include "HandleWaterTempAction.h"

HandleWaterTempAction::HandleWaterTempAction(RelayController* c,
    UsbController* uController,
    ReadWaterTemperatureController* tempC) : Action(uController){
  controller = c;
  tempController = tempC;
  pinMode(WATER_TEMP_PIN, OUTPUT);
}

void HandleWaterTempAction::executeAction(char* inputString) {
  if(strstr(inputString, WATER_ON_ACTION) != NULL) {
    controller->turnOn();
    usbController->sendString(OK);
    freeResources();
  } else if(strstr(inputString, WATER_OFF_ACTION) != NULL) {
    controller->turnOff();
    usbController->sendString(OK);
    freeResources();
  } else if (strstr(inputString, WATER_GET_ACTION) != NULL) {
    usbController->sendString(String(tempController->readTemperature()));
    freeResources();
  }
}

void HandleWaterTempAction::freeResources() {
  free(controller);
  free(tempController);
  free(usbController);
}
