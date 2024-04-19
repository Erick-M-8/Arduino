//Emisor
void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.print("Hola\n");
  delay(5000);
  Serial.print("Adios\n");  
  delay(5000);
}


