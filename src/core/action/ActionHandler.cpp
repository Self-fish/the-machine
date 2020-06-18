#include "ActionHandler.h"

ActionHandler::ActionHandler() {
  LiquidCrystal_I2C lcd(0x27, 20, 4);
  lcd.begin();
  lcd.backlight();
  DHT humiditySensor(HUMIDITY_PIN, DHTTYPE);
  humiditySensor.begin();
  OneWire ourWire(WATER_TEMPERATURE_PIN);
  DallasTemperature waterSensor(&ourWire);
  waterSensor.begin();
  actionBuilder = ActionBuilder();
  actionBuilder.initialise(&lcd, &humiditySensor, &waterSensor);
}

unsigned long ActionHandler::run() {
  Serial.println("Run!");
  char action[100];
  if(Serial.available()) {
    Serial.readString().toCharArray(action, 100);
    executeAction(action);
  }
  delay(1000);
  return 0;
}

void ActionHandler::executeAction(char command[100]) {
  action = actionBuilder.build(command);
  action->executeAction(command);
  free(action);
  Serial.println(freeMemory());
}
