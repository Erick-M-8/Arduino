//Un servomotor hace giros según los grados indicados 

#include<Servo.h>
Servo servo1;

void setup() {
  servo1.attach(3);
}

void loop() {
  servo1.write(0);
  delay(2000);
  servo1.write(90);
  delay(2000);
  servo1.write(180);
  delay(2000);
}
