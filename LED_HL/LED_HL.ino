//El led enciende y apaga cada que pasa 1 segundo

int led = 2 

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
