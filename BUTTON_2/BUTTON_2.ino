//Enciende un led al presionar un botón, y se apaga al soltarlo

const int BUTTON = 2;
const int LED = 8;
int BUTTONSTATE = 0;

void setup() {
  pinMode (LED, OUTPUT); 
  pinMode (BUTTON, INPUT);
}

void loop() {
  BUTTONSTATE = digitalRead(BUTTON);
  if(BUTTONSTATE == HIGH){
    digitalWrite (LED, HIGH);
  }
  else{
     digitalWrite (LED, LOW);
  }
}
