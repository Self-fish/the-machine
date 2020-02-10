#ifndef CoreInyector_h
#define CoreInyector_h

#include "controller/UsbController.h"
#include "controller/LCDController.h"
#include "controller/CurrentStatusController.h"

class CoreInyector {
public:
  CoreInyector();
  void initialise(LiquidCrystal_I2C* l,
    CurrentStatusController* sController);
  UsbController* getUsbController();
  LCDController* getLCDController();
  CurrentStatusController* getCurrentStatusController();

private:
  LiquidCrystal_I2C* lcd;
  CurrentStatusController* statusController;
};


#endif
