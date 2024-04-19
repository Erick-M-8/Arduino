//Enciende un led al presionar un botón, y se apaga al soltarlo (a cada led e corresponde un botón diferente)

const int BUTTON1 = 2;
const int BUTTON2 = 3;
const int LED1 = 8;
const int LED2 = 9;

int BUTTON1STATE = 0;
int BUTTON2STATE = 0;

void setup() {
  pinMode (LED1, OUTPUT); 
  pinMode (LED2, OUTPUT); 
  pinMode (BUTTON1, INPUT);
  pinMode (BUTTON2, INPUT);
}

void loop() {
  BUTTON1STATE = digitalRead(BUTTON1);
  BUTTON2STATE = digitalRead(BUTTON2);
  
  if(BUTTON1STATE == HIGH){
    digitalWrite (LED1, HIGH);
  }
  else{
     digitalWrite (LED1, LOW);
  }

  if(BUTTON2STATE == HIGH){
    digitalWrite (LED2, HIGH);
  }
  else{
     digitalWrite (LED2, LOW);
  }
}
