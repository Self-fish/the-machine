#ifndef ActionBuilder_h
#define ActionBuilder_h

#include "../../ShowBoxHumidityUseCase/ShowBoxHumidityInyector.h"
#include "../../ShowBoxTemperatureUseCase/ShowBoxTemperatureInyector.h"
#include "../../ShowWelcomeUseCase/ShowWelcomeInyector.h"
#include "../../ShowMainScreenUseCase/ShowMainScreenInyector.h"
#include "../../MachineConfigurationUseCase/MachineConfigurationInyector.h"
#include "../../ShowWaterTemperatureUseCase/ShowWaterTemperatureInyector.h"
#include "../../HandleLightsUseCase/HandleLightsInyector.h"
#include "../controller/CurrentStatusController.h"

class ActionBuilder {
public:
  ActionBuilder();
  Action* build(char* action);
  void initialise(LiquidCrystal_I2C* lcd,
    DHT* humiditySensor, DallasTemperature* temperatureSensor);

private:
  static CurrentStatusController* currentStatusController;
  ShowBoxHumidityInyector boxHumidityInyector;
  ShowWelcomeInyector welcomeInyector;
  ShowMainScreenInyector mainScreenInyector;
  MachineConfigurationInyector configurationInyector;
  ShowBoxTemperatureInyector boxTemperatureInyector;
  ShowWaterTemperatureInyector waterTemperatureInyector;
  HandleLightsInyector handleLightsInyector;
  CurrentStatusController* getStatusControllerInstance();


};


#endif
