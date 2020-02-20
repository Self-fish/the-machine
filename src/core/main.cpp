#include <Arduino.h>
#include "action/ActionBuilder.h"
#include "../../lib/MemoryFree/MemoryFree.h"

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
  pinMode(LIGHTS_PIN, OUTPUT);
  actionBuilder.initialise(&lcd, &humiditySensor, &waterSensor);
  executeAction("S_W");
}

void loop() {
  /*char charAction[100];
  if(Serial.available()) {
    String actionString = Serial.readString();
    actionString.toCharArray(charAction, 100);
    executeAction(charAction);
  }*/
  Serial.println(freeMemory());
  executeAction("L_N");
  executeAction("L_G");
  delay(1000);
  executeAction("L_F");
  executeAction("L_G");
  delay(1000);
  executeAction("CON:12345678");
  delay(1000);
  executeAction("H_U");
  delay(1000);
  executeAction("T_U");
  delay(1000);
  executeAction("W_U");
  delay(1000);
}
