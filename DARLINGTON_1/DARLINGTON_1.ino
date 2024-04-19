/*
  Relevador 1
  Circuito primario activado por un sensor de 24VCD
  Circuito secundario conectado a 5VCD
  Relevador2
  Circuito primario activado por un arreglo darlington 5V
  Circuito secundario conectado a 220VCA

  Si el relé 1 es activado por el sensor este envia una señal HIGH al pin 2, provocando que el pin 8 
  envie una señal hacia el arreglo darlington, lo que cierra el circuito primario del relé 2 y permite 
  que se cierre el circuito secundario, lo que encendiende el foco
  
*/

const int RELE = 2;
const int FOCO = 8;

int RELESTATE = 0;

//Include library code LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode (FOCO, OUTPUT); 
  pinMode (RELE, INPUT);
  

  lcd.setCursor(0,0);
  lcd.print("Sis. Embebidos0!");
  lcd.setCursor(3,1);
  lcd.print("6 semestre");
  delay(2000);
  lcd.clear();
  lcd.setCursor(3,0);  
  lcd.print("Prac.4");
  delay(2000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Sistema de");
  lcd.setCursor(1,1);
  lcd.print("Control");
  delay(2000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Realizado:");
  lcd.setCursor(0,1);
  lcd.print("Erick Montoya B");
  delay(1000);  
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Realizado:");
  lcd.setCursor(0,1);
  lcd.print("Oliver Gamboa H");
  delay(1000);  
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Realizado:");
  lcd.setCursor(0,1);
  lcd.print("Edson Hernandez G");
  delay(1000);  
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Realizado:");
  lcd.setCursor(0,1);
  lcd.print("Aaron S Sanchez F");
  delay(1000);  
  lcd.clear();
 }  
void loop() {
  RELESTATE = digitalRead(RELE);
  // coniguracion de los numeros de columnas y lineas de LCD
  if (RELESTATE  == HIGH){
    lcd.setCursor (0,0);  
    lcd.print("Foco encendido");
    digitalWrite(FOCO,HIGH);
    delay(2000);
    lcd.clear();
  }
  else{
    lcd.setCursor (0,0);  
    digitalWrite(FOCO,LOW);
    lcd.print("Foco apagado");
  }

 }