#ifndef ShowBoxHumidityInyector_h
#define ShowBoxHumidityInyector_h

#include "action/ShowBoxHumidityAction.h"
#include "../core/CoreInyector.h"

class ShowBoxHumidityInyector: public CoreInyector {
public:
  ShowBoxHumidityInyector();
  void initialise(LiquidCrystal_I2C* l, DHT* h, ShowMainScreenUseCase* mUseCase,
    CurrentStatusController* sController);
  ShowBoxHumidityAction* getBoxHumidityAction();

private:
  static ShowBoxHumidityAction* actionInstance;

  DHT* humiditySensor;
  ShowMainScreenUseCase* mainScreenUseCase;
  ShowBoxHumidityUseCase* getBoxHUmidityUseCase();
  ReadHumidityController* getHumidityController();
  BoxHumidityScreenController* getBoxHumidityScreenController();
};


#endif
