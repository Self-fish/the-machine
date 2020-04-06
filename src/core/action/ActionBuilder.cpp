#include "ActionBuilder.h"

ActionBuilder::ActionBuilder() {
  currentStatusController = new CurrentStatusController();
  alertsController = new AlertsController();
}

Action* ActionBuilder::build(char* input) {
  if(strstr(input, UPDATE_HUMIDITY_ACTION) != NULL) {
    return new ShowBoxHumidityAction(new ShowBoxHumidityUseCase(
      new ReadHumidityController(humiditySensor),
      new BoxHumidityScreenController(new LCDController(lcd))),
      new ShowMainScreenUseCase(new MainScreenController(new LCDController(lcd),
      currentStatusController), new GetTimeController()), new UsbController());
  } else if(strstr(input, SHOW_WELCOME_SCREEN_ACTION) != NULL) {
    return new ShowWelcomeAction(new ShowWelcomeUseCase(new WelcomeScreenController(
      new LCDController(lcd), currentStatusController)), new UsbController());
  } else if(strstr(input, CONFIGURE_ACTION) != NULL) {
    return new MachineConfigurationAction(new TimeController(),
      new UsbController());
  } else if(strstr(input, UPDATE_TEMPERATURE_ACTION) != NULL) {
    return new ShowBoxTemperatureAction(new ShowBoxTemperatureUseCase(new ReadTemperatureController(humiditySensor),
      new BoxTemperatureScreenController(new LCDController(lcd))),
      new ShowMainScreenUseCase(new MainScreenController(new LCDController(lcd),
      currentStatusController), new GetTimeController()),
      new UsbController());
  } else if(strstr(input, UPDATE_WATER_TEMPERATURE_ACTION) != NULL) {
    return new ShowWaterTemperatureAction(new ShowWaterTemperatureUseCase(new ReadWaterTemperatureController(temptSensor),
      new WaterTemperatureScreenController(new LCDController(lcd))),
      new ShowMainScreenUseCase(new MainScreenController(new LCDController(lcd),
      currentStatusController), new GetTimeController()),
      new UsbController());
  } else if(strstr(input, LIGHT_ON_ACTION) != NULL ||
      strstr(input, LIGHT_OFF_ACTION) != NULL ||
      strstr(input, LIGHT_GET_ACTION) != NULL) {
    return new HandleLightsAction(new RelayController(LIGHTS_PIN),
      new UsbController());
  } else if(strstr(input, WATER_ON_ACTION) != NULL ||
      strstr(input, WATER_OFF_ACTION) != NULL ||
      strstr(input, WATER_GET_ACTION) != NULL) {
    return new HandleWaterTempAction(new RelayController(WATER_TEMP_PIN),
      new UsbController(), new ReadWaterTemperatureController(temptSensor));
  } else if(strstr(input, RECEIVE_ALERTS_ACTION) != NULL) {
    return new HandleAlertsAction(new UsbController(),
      new StoreAlertUseCase(alertsController));
  } else if(strstr(input, SHOW_ALERTS_ACTION) != NULL) {
    return new ShowAlertsAction(new ShowAlertsUseCase(new AlertTimeController(),
      new AlertScreenController(new LCDController(lcd), currentStatusController),
      alertsController), new UsbController());
  }
}

void ActionBuilder::initialise(
    LiquidCrystal_I2C* l, DHT* hSensor,
    DallasTemperature* temperatureSensor) {
  temptSensor = temperatureSensor;
  humiditySensor = hSensor;
  lcd = l;
}
