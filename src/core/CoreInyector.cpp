#include "CoreInyector.h"

CoreInyector::CoreInyector() {}

void CoreInyector::initialise(LiquidCrystal_I2C *l,
    CurrentStatusController* sController) {
  lcd = l;
  statusController = sController;
}

UsbController* CoreInyector::getUsbController() {
  return new UsbController();
}

LCDController* CoreInyector::getLCDController() {
  return new LCDController(lcd);
}

CurrentStatusController* CoreInyector::getCurrentStatusController() {
  return statusController;
}
