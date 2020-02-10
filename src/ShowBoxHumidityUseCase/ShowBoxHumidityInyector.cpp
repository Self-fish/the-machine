#include "ShowBoxHumidityInyector.h"

ShowBoxHumidityAction* ShowBoxHumidityInyector::actionInstance = 0;

ShowBoxHumidityInyector::ShowBoxHumidityInyector() {}

void ShowBoxHumidityInyector::initialise(LiquidCrystal_I2C* l, DHT* h,
    ShowMainScreenUseCase* mUseCase, CurrentStatusController* sController) {
  CoreInyector::initialise(l, sController);
  humiditySensor = h;
  mainScreenUseCase = mUseCase;
}

ShowBoxHumidityAction* ShowBoxHumidityInyector::getBoxHumidityAction() {
  if(actionInstance == 0) {
    actionInstance = new ShowBoxHumidityAction(getBoxHUmidityUseCase(), mainScreenUseCase,
      getUsbController());
  }
  return actionInstance;
}

ShowBoxHumidityUseCase* ShowBoxHumidityInyector::getBoxHUmidityUseCase() {
  return new ShowBoxHumidityUseCase(getHumidityController(),
    getBoxHumidityScreenController());
}

ReadHumidityController* ShowBoxHumidityInyector::getHumidityController() {
  return new ReadHumidityController(humiditySensor);
}

BoxHumidityScreenController* ShowBoxHumidityInyector::getBoxHumidityScreenController() {
  return new BoxHumidityScreenController(getLCDController());
}
