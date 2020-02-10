#include "ShowWaterTemperatureInyector.h"

ShowWaterTemperatureAction* ShowWaterTemperatureInyector::actionInstance = 0;

ShowWaterTemperatureInyector::ShowWaterTemperatureInyector() {}

void ShowWaterTemperatureInyector::initialise(LiquidCrystal_I2C* l,
    ShowMainScreenUseCase* mUseCase, CurrentStatusController* sController,
    DallasTemperature* tSensor) {
  CoreInyector::initialise(l, sController);
  mainScreenUseCase = mUseCase;
  temperatureSensor = tSensor;
}

ShowWaterTemperatureAction* ShowWaterTemperatureInyector::getWaterTemperatureAction() {
  if(actionInstance == 0) {
    actionInstance = new ShowWaterTemperatureAction(getWaterTemperatureUseCase(),
    mainScreenUseCase, getUsbController());
  }
  return actionInstance;
}

ShowWaterTemperatureUseCase* ShowWaterTemperatureInyector::getWaterTemperatureUseCase() {
  return new ShowWaterTemperatureUseCase(getWaterTemperatureController(),
    getWaterTemperatureScreenController());
}

ReadWaterTemperatureController* ShowWaterTemperatureInyector::getWaterTemperatureController() {
  return new ReadWaterTemperatureController(temperatureSensor);
}

WaterTemperatureScreenController* ShowWaterTemperatureInyector::getWaterTemperatureScreenController() {
  return new WaterTemperatureScreenController(getLCDController());
}
