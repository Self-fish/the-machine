#include "UsbController.h"

UsbController::UsbController(){}

void UsbController::sendString(String string) {
  for(char& c : string) {
    Serial.write(c);
    delay(1000);
  }
  Serial.write('\n');
}
