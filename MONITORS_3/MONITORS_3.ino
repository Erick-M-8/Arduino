//Se imprime las tablas de multiplicar en el monitor serial

int i = 1;
int j = 1; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(i);
  Serial.print("*");
  Serial.print(j);
  Serial.print("=");
  Serial.println(i*j);
  j++;
  if((j-1)%10==0){
    j=1;
    i++;
    Serial.println("");
  }
  delay(2000);
}
