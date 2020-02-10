#ifndef ShowBoxHumidityAction_h
#define ShowBoxHumidityAction_h

#include "Arduino.h"
#include "../../core/action/Action.cpp"
#include "../domain/ShowBoxHumidityUseCase.h"
#include "../../ShowMainScreenUseCase/domain/ShowMainScreenUseCase.h"

class ShowBoxHumidityAction: public Action {
public:
  ShowBoxHumidityAction(ShowBoxHumidityUseCase* hUseCase,
    ShowMainScreenUseCase* mUseCase, UsbController* uController);
  void executeAction(char* inputString);

private:
  ShowBoxHumidityUseCase* humidityUseCase;
  ShowMainScreenUseCase* mainScreenUseCase;
};


#endif
