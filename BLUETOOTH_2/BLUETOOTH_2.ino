

#include <Wire.h>

char estado;

void setup() {
  Serial.begin(9600);
  pinMode (13, OUTPUT);
  pinMode (12, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    estado = Serial.read();
  }
  if (estado == 'a') {
    digitalWrite (13, HIGH);
    delay(500);
  }
  if (estado == 'b') {
    digitalWrite (13, LOW);
    delay(500);
  }
  if (estado == 'c') {
    digitalWrite (12, HIGH);
    delay(500);
  }
  if (estado == 'd') {
    digitalWrite (12, LOW);
    delay(500);
  }
}
