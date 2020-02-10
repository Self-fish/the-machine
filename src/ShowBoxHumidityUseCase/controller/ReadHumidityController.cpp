#include "ReadHumidityController.h"

ReadHumidityController::ReadHumidityController(DHT* h){
  humiditySensor = h;
}

double ReadHumidityController::readHumidity() {
  return humiditySensor->readHumidity();
}
