#ifndef ShowBoxTemperatureAction_h
#define ShowBoxTemperatureAction_h

#include "Arduino.h"
#include "../../core/action/Action.cpp"
#include "../domain/ShowBoxTemperatureUseCase.h"
#include "../../ShowMainScreenUseCase/domain/ShowMainScreenUseCase.h"

class ShowBoxTemperatureAction: public Action {
public:
  ShowBoxTemperatureAction(ShowBoxTemperatureUseCase* tUseCase,
    ShowMainScreenUseCase* mUseCase, UsbController* uController);
  void executeAction(char* inputString);

private:
  ShowBoxTemperatureUseCase* temperatureUseCase;
  ShowMainScreenUseCase* mainScreenUseCase;
};


#endif
