/* 
 P12 -> RS
 P11 -> E
 P5 -> D4
 P4 -> D5
 P3 -> D6
 P2 -> D7
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  //Configuracion de los números de columnas y leneas del LCD
  lcd.begin(16, 2);
  lcd.print("Hola, mundo!");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write("ING-INFORMATICA");
  delay(2000);
  lcd.setCursor(0,1);
  lcd.write("SIS-EMBEBIDOS");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write("6-SEMESTRE");
  delay(2000);
  lcd.clear();
}

void loop() {

}
