#include "LCDController.h"

LCDController::LCDController(LiquidCrystal_I2C* l){
  lcd = l;
}

void LCDController::printText(int column, int row, String text) {
  lcd->setCursor(column,row);
  lcd->print(text);
}

void LCDController::createSpecialCharacters(byte character[8], int position) {
  lcd->createChar(position, character);
}

void LCDController::writeCharacter(int position, int column, int row) {
  lcd->setCursor(column, row);
  lcd->write(byte(position));
}

void LCDController::cleanScreen() {
  lcd->clear();
}

void LCDController::cleanRow(int row) {
  lcd->setCursor(0, row);
  lcd->print("                    ");
}

void LCDController::cleanCharacter(int row, int column) {
  lcd->setCursor(row, column);
  lcd->print(" ");
}
