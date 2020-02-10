#ifndef ShowWaterTemperatureInyector_h
#define ShowWaterTemperatureInyector_h

#include "action/ShowWaterTemperatureAction.h"
#include "../core/CoreInyector.h"

class ShowWaterTemperatureInyector: public CoreInyector {
public:
  ShowWaterTemperatureInyector();
  void initialise(LiquidCrystal_I2C* l, ShowMainScreenUseCase* mUseCase,
    CurrentStatusController* sController, DallasTemperature* tSensor);
  ShowWaterTemperatureAction* getWaterTemperatureAction();

private:
  static ShowWaterTemperatureAction* actionInstance;
  ShowWaterTemperatureUseCase* getWaterTemperatureUseCase();
  ReadWaterTemperatureController* getWaterTemperatureController();
  WaterTemperatureScreenController* getWaterTemperatureScreenController();
  DallasTemperature* temperatureSensor;
  ShowMainScreenUseCase* mainScreenUseCase;
};


#endif
