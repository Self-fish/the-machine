#include "ShowBoxTemperatureInyector.h"

ShowBoxTemperatureAction* ShowBoxTemperatureInyector::actionInstance = 0;

ShowBoxTemperatureInyector::ShowBoxTemperatureInyector() {}

void ShowBoxTemperatureInyector::initialise(LiquidCrystal_I2C* l, DHT* t,
    ShowMainScreenUseCase* mUseCase, CurrentStatusController* sController) {
  CoreInyector::initialise(l, sController);
  temperatureSensor = t;
  mainScreenUseCase = mUseCase;
}

ShowBoxTemperatureAction* ShowBoxTemperatureInyector::getBoxTemperatureAction() {
  if(actionInstance == 0) {
    actionInstance = new ShowBoxTemperatureAction(getBoxTemperatureUseCase(), mainScreenUseCase,
      getUsbController());
  }
  return actionInstance;
}

ShowBoxTemperatureUseCase* ShowBoxTemperatureInyector::getBoxTemperatureUseCase() {
  return new ShowBoxTemperatureUseCase(getTemperatureController(),
    getBoxTemperatureScreenController());
}

ReadTemperatureController* ShowBoxTemperatureInyector::getTemperatureController() {
  return new ReadTemperatureController(temperatureSensor);
}

BoxTemperatureScreenController* ShowBoxTemperatureInyector::getBoxTemperatureScreenController() {
  return new BoxTemperatureScreenController(getLCDController());
}
