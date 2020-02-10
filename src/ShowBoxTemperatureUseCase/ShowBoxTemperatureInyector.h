#ifndef ShowBoxTemperatureInyector_h
#define ShowBoxTemperatureInyector_h

#include "action/ShowBoxTemperatureAction.h"
#include "../core/CoreInyector.h"

class ShowBoxTemperatureInyector: public CoreInyector {
public:
  ShowBoxTemperatureInyector();
  void initialise(LiquidCrystal_I2C* l, DHT* t, ShowMainScreenUseCase* mUseCase,
    CurrentStatusController* sController);
  ShowBoxTemperatureAction* getBoxTemperatureAction();

private:
  static ShowBoxTemperatureAction* actionInstance;

  DHT* temperatureSensor;
  ShowMainScreenUseCase* mainScreenUseCase;
  ShowBoxTemperatureUseCase* getBoxTemperatureUseCase();
  ReadTemperatureController* getTemperatureController();
  BoxTemperatureScreenController* getBoxTemperatureScreenController();
};


#endif
