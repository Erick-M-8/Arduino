/*Un led enciende cuando se presiona el boton,
y se apaga después de 2 segundos*/

#define LED 8
#define BUTTON 2

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  if(digitalRead (BUTTON)== HIGH)
  {
    digitalWrite(LED, HIGH);
    delay(2000);
    digitalWrite(LED, LOW);
    delay(2000);
  }
}
