#ifndef ActionBuilder_h
#define ActionBuilder_h

#include "../controller/CurrentStatusController.h"
#include "../../HandleLightsUseCase/action/HandleLightsAction.h"
#include "../../HandleWaterTempUseCase/action/HandleWaterTempAction.h"
#include "../../MachineConfigurationUseCase/action/MachineConfigurationAction.h"
#include "../../ShowBoxHumidityUseCase/action/ShowBoxHumidityAction.h"
#include "../../ShowBoxTemperatureUseCase/action/ShowBoxTemperatureAction.h"
#include "../../ShowWaterTemperatureUseCase/action/ShowWaterTemperatureAction.h"
#include "../../ShowWelcomeUseCase/action/ShowWelcomeAction.h"
#include "../../HandleAlertsUseCase/action/HandleAlertsAction.h"
#include "../../ShowAlertsUseCase/action/ShowAlertsAction.h"

class ActionBuilder {
public:
  ActionBuilder();
  Action* build(const char* action);
  void initialise(LiquidCrystal_I2C* l,
    DHT* hSensor, DallasTemperature* temperatureSensor/*,
    JoystickController* jController*/);

private:
  DallasTemperature* temptSensor;
  DHT* humiditySensor;
  LiquidCrystal_I2C *lcd;
  //JoystickController* joystickController;
  CurrentStatusController* currentStatusController;
  //AlertsController* alertsController;

};


#endif
