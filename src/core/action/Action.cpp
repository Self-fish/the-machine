#ifndef Action_cpp
#define Action_cpp

#include "Arduino.h"
#include "../controller/UsbController.h"

class Action {
  public:

    UsbController* usbController;

    Action(UsbController* uController) {
      usbController = uController;
    }

    virtual void executeAction(char* inputString) = 0;

  private:

};

#endif
