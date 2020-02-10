#ifndef UsbController_h
#define UsbController_h

#include "Arduino.h"

#define OK "OK"

class UsbController {
public:
  UsbController();
  void sendString(String string);
};


#endif
