#ifndef LCDController_h
#define LCDController_h

#include "Arduino.h"
#include "../../../lib/I2C/LiquidCrystal_I2C.h"

class LCDController {

public:
  LCDController(LiquidCrystal_I2C* l);
  void printText(int column, int row, String text);
  void createSpecialCharacters(byte character[8], int position);
  void writeCharacter(int position, int column, int row);
  void cleanScreen();
  void cleanRow(int row);

private:
  LiquidCrystal_I2C* lcd;
};


#endif
