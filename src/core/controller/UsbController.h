#ifndef UsbController_h
#define UsbController_h

#include "Arduino.h"

#define OK "OK"
#define ON "ON"
#define OFF "OFF"

class UsbController {
public:
  UsbController();
  void sendString(String string);
};


#endif
