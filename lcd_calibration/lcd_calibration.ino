#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();  
  lcd.backlight();
  lcd.print("CODEGATE!");
}

void loop() {
  // put your main code here, to run repeatedly:
}