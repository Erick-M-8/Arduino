//Se imprime la variable i (que al inicio vale 0 y aumenta uno cada iteración), en el monitor serial

int i = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("i = ");
  Serial.println(i);
  i++;
  delay(3000);
}
