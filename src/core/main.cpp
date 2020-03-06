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
  free(action);
  Serial.println(freeMemory());
}

void setup() {
  Serial.begin(9600);
  delay(1000);
  waterSensor.begin();
  humiditySensor.begin();
  lcd.begin();
  lcd.backlight();
  pinMode(LIGHTS_PIN, OUTPUT);
  digitalWrite(LIGHTS_PIN, HIGH);
  pinMode(WATER_TEMP_PIN, OUTPUT);
  digitalWrite(WATER_TEMP_PIN, HIGH);
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(BUTTON_PIN, HIGH);
  actionBuilder.initialise(&lcd, &humiditySensor, &waterSensor);
  //executeAction("S_W");
}

void loop() {
  executeAction("S_A");
  delay(1000);

  /*char charAction[100];
  if(Serial.available()) {
    String actionString = Serial.readString();
    actionString.toCharArray(charAction, 100);
    executeAction(charAction);
  }*/
}
