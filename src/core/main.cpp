#include <Arduino.h>
#include "action/ActionBuilder.h"
#include "../../lib/MemoryFree/MemoryFree.h"

#define WATER_TEMPERATURE_PIN 10
#define HUMIDITY_PIN 6
#define DHTTYPE DHT22

Action* action;
OneWire ourWire(WATER_TEMPERATURE_PIN);
DallasTemperature waterSensor(&ourWire);
LiquidCrystal_I2C lcd(0x27, 20, 4);
DHT humiditySensor(HUMIDITY_PIN, DHTTYPE);

ActionBuilder actionBuilder = ActionBuilder();

void executeAction(char actionString[100]) {
  action = actionBuilder.build(actionString);
  action->executeAction(actionString);
}

void setup() {
  Serial.begin(9600);
  delay(1000);
  waterSensor.begin();
  humiditySensor.begin();
  lcd.begin();
  lcd.backlight();
  actionBuilder.initialise(&lcd, &humiditySensor, &waterSensor);
  executeAction("S_W");
  Serial.println(freeMemory());
}

void loop() {
  char charAction[100];
  if(Serial.available()) {
    String actionString = Serial.readString();
    actionString.toCharArray(charAction, 100);
    executeAction(charAction);
  }
}
