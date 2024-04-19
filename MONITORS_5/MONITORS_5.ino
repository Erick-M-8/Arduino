
// El monitor serial muestra la temperatura utilizando el sensor LM35

const int LM35 = A0;
float temperatura;

void setup() {
  Serial.begin(9600);
  Serial.println("ADC Arduino");
  delay(2000);
}

void loop() {
  temperatura = ((float(analogRead(LM35)) * 5.0 )/(1023 * 0.01));
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" oC");
  delay(1000);
}
