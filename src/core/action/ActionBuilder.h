#ifndef ActionBuilder_h
#define ActionBuilder_h

#include "../../ShowBoxHumidityUseCase/ShowBoxHumidityInyector.h"
#include "../../ShowBoxTemperatureUseCase/ShowBoxTemperatureInyector.h"
#include "../../ShowWelcomeUseCase/ShowWelcomeInyector.h"
#include "../../ShowMainScreenUseCase/ShowMainScreenInyector.h"
#include "../../MachineConfigurationUseCase/MachineConfigurationInyector.h"
#include "../../ShowWaterTemperatureUseCase/ShowWaterTemperatureInyector.h"
#include "../controller/CurrentStatusController.h"

class ActionBuilder {
public:

  const char UPDATE_TEMPERATURE_ACTION[4] = "T_U";
  const char UPDATE_HUMIDITY_ACTION[4] = "H_U";
  const char UPDATE_WATER_TEMPERATURE_ACTION[4] = "W_U";
  const char SHOW_WELCOME_SCREEN_ACTION[4] = "S_W";
  const char CONFIGURE_ACTION[4] = "CON";

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
  CurrentStatusController* getStatusControllerInstance();


};


#endif
