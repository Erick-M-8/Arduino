/*
  Relevadores externos
  Circuito primario activado por un sensor de 24VCD
  Circuito secundario conectado a 5VCD
  Relevadores
  Circuito primario activado por un arreglo darlington 5VCD
  Circuito secundario conectado a 9VCD
  -Corriente en NA
  -Tierra en NC
  -La que se consideraba como entrada del relé en el progrma anterior ahora es una salida
  Motor de CD
  Gira en un sentido u otro dependiendo de la alimentación,
  si ambos cables tienen LOW o HIGH el motor no gira.

  Si se activa un relevador externo, se envia la señal HIGH a una de las entradas (PIN 2 o 3), 
  lo que provoca que su respectiva salida (PIN 8 o 9), envie la señal HIGH al arreglo darlington
  esto activa el relé, el cual permite el paso de corriente hacia uno de los polos del motor
*/

const int D2 = 9;  //Darlington
const int D1 = 8;  //Darlington
const int S2 = 3;  //Sensor
const int S1 = 2;  //Sensor

int S1STATE = 0;
int S2STATE = 0;

//Include library code LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  
  //Presentación
  lcd.setCursor(0, 0);
  lcd.print("Sis. Embebidos0!");
  lcd.setCursor(3, 1);
  lcd.print("6 semestre");
  delay(2000);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Prac.6");
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
  lcd.clear();
}
void loop() {
  S1STATE = digitalRead(S1);
  S2STATE = digitalRead(S2);
  // coniguracion de los numeros de columnas y lineas de LCD
  if (S1STATE == HIGH) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor 1  On");
    digitalWrite(D1, HIGH);
  } else {
    lcd.setCursor(0, 0);
    digitalWrite(D1, LOW);
    lcd.print("Sensor 1 Off");  // Izquierda
  }

  if (S2STATE == HIGH) {
    lcd.setCursor(0, 1);
    lcd.print("Sensor 2 On");  //derecha
    digitalWrite(D2, HIGH);
  } else {
    lcd.setCursor(0, 1);
    digitalWrite(D2, LOW);
    lcd.print("Sensor 2 Off");
  }
 }