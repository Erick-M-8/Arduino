char dato; 
#define Led 13
void setup() {
  pinMode(Led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    dato = Serial.read();
    Serial.println("Comunicación exitosa");
    Serial.println(dato);
    if (dato == '1') {
      digitalWrite(Led, HIGH);
    } else if (dato == '0') {
      digitalWrite(Led, LOW);
    }
  }
}
