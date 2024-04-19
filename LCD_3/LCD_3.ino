/*
Cada sensor activa su respectivo LED. En el LCD se muestra el sensor activado
y se limpia el LCD cuando el LED se apaga después de 2 segundos.
*/

const int SENSOR1 = 2;
const int SENSOR2 = 3;
const int LED1 = 8;
const int LED2 = 9;
int SENSOR1STATE = 0;
int SENSOR2STATE = 0;

// Incluir bibliotecas para el LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Sis. Embebidos!");
  lcd.setCursor(3, 1);
  lcd.print("6 semestre");
  delay(2000);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Prac.1");
  delay(2000);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Sistema de");
  lcd.setCursor(1, 1);
  lcd.print("Control");
  delay(2000);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Realizado:");
  lcd.setCursor(0, 1);
  lcd.print("Erick Montoya B");
  delay(1000);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Realizado:");
  lcd.setCursor(0, 1);
  lcd.print("Oliver Gamboa H");
  delay(1000);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Realizado:");
  lcd.setCursor(0, 1);
  lcd.print("Edson Hernandez G");
  delay(1000);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Realizado:");
  lcd.setCursor(0, 1);
  lcd.print("Aaron S Sanchez F");
  delay(1000);
}

void loop() {
  SENSOR1STATE = digitalRead(SENSOR1);
  SENSOR2STATE = digitalRead(SENSOR2);

  // Configuración de los números de columnas y líneas del LCD
  if (SENSOR1STATE == HIGH) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor_1");
    digitalWrite(LED1, HIGH);
    delay(2000);
    digitalWrite(LED1, LOW);
    lcd.clear();
    delay(1000);
  } else {
    lcd.clear();
  }

  if (SENSOR2STATE == HIGH) {
    lcd.setCursor(0, 1);
    lcd.print("Sensor_2");
    digitalWrite(LED2, HIGH);
    delay(2000);
    digitalWrite(LED2, LOW);
    lcd.clear();
    delay(1000);
  } else {
    lcd.clear();
  }
}