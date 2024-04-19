//Include library code LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hola mundo");
  lcd.setCursor(3,1);
  lcd.print("I2C Arduino");
 }  
void loop() {
}
