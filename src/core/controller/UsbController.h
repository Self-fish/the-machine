#ifndef UsbController_h
#define UsbController_h

#include "Arduino.h"

#define OK "OK"
#define ON "ON"
#define OFF "OFF"
#define LATER_RESPONSE "LAT"

class UsbController {
public:
  UsbController();
  void sendString(String string);
};


#endif
