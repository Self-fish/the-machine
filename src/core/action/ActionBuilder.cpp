#include "ActionBuilder.h"

CurrentStatusController* ActionBuilder::currentStatusController = 0;

ActionBuilder::ActionBuilder() {
  boxHumidityInyector = ShowBoxHumidityInyector();
  welcomeInyector = ShowWelcomeInyector();
  mainScreenInyector = ShowMainScreenInyector();
  configurationInyector = MachineConfigurationInyector();
  boxTemperatureInyector = ShowBoxTemperatureInyector();
  waterTemperatureInyector = ShowWaterTemperatureInyector();
}

Action* ActionBuilder::build(char* input) {
  if(strstr(input, UPDATE_HUMIDITY_ACTION) != NULL) {
    return boxHumidityInyector.getBoxHumidityAction();
  } else if(strstr(input, SHOW_WELCOME_SCREEN_ACTION) != NULL) {
    return welcomeInyector.getShowWelcomeAction();
  } else if(strstr(input, CONFIGURE_ACTION) != NULL) {
    return configurationInyector.getMachineConfigurationAction();
  } else if(strstr(input, UPDATE_TEMPERATURE_ACTION) != NULL) {
    return boxTemperatureInyector.getBoxTemperatureAction();
  } else if(strstr(input, UPDATE_WATER_TEMPERATURE_ACTION) != NULL) {
    return waterTemperatureInyector.getWaterTemperatureAction();
  }
}

void ActionBuilder::initialise(
    LiquidCrystal_I2C* lcd, DHT* humiditySensor,
    DallasTemperature* temperatureSensor) {
  mainScreenInyector.initialise(lcd, getStatusControllerInstance());
  boxHumidityInyector.initialise(lcd, humiditySensor,
    mainScreenInyector.getShowMainScreenUseCase(), getStatusControllerInstance());
  welcomeInyector.initialise(lcd, getStatusControllerInstance());
  boxTemperatureInyector.initialise(lcd, humiditySensor,
    mainScreenInyector.getShowMainScreenUseCase(), getStatusControllerInstance());
  waterTemperatureInyector.initialise(lcd, mainScreenInyector.getShowMainScreenUseCase(),
    getStatusControllerInstance(), temperatureSensor);
}

CurrentStatusController* ActionBuilder::getStatusControllerInstance() {
  if(currentStatusController == 0) {
    currentStatusController = new CurrentStatusController();
  }
  return currentStatusController;
}
