// Declarar el numero de pines del arduino que se asignan a cada variable
//int frePin = 2;         // Entrada Sensor Frente X
//int derPin = 3;         // Entrada Sensor Derecho Y
//int izqPin = 4;         // Entrada Sensor Izquierdo Z
//int atrPin = 5;         // Entrada Sensor Atras T
//int abaPin = 6;         // Entrada Sensor Debajo Q

#define FRONT_TRIG_PIN 2
#define FRONT_ECHO_PIN 3

#define RIGHT_TRIG_PIN 24
#define RIGHT_ECHO_PIN 25

#define LEFT_TRIG_PIN 26
#define LEFT_ECHO_PIN 27

#define BACK_TRIG_PIN 28
#define BACK_ECHO_PIN 29

#define CAPACITIVE_SENSOR_PIN 53
int MotDerFrePin = 4;   // Salida Motor derecho hacia en frente
int MotDerRevPin = 5;   // Salida Motor derecho reversa
int MotIzqFrePin = 9;   // Salida Motor izquierdo hacia en frente
int MotIzqRevPin = 10;  // Salida Motor izquierdo reversa
//int paroPin = 11; //boton de emergencia



// Declarar salidas como booleanos
bool estadofre;       //Variable para almacenar el estado del sensor Frente
bool estadoder;       //Variable para almacenar el estado del sensor Derecho
bool estadoizq;       //Variable para almacenar el estado del sensor Izquierdo
bool estadoatr;       //Variable para almacenar el estado del sensor Atras
bool estadoaba;       //Variable para almacenar el estado del sensor Debajo
bool estadoParo;      //Variable para almacenar el paro de emergencia
bool estadoArranque;  //Variable para almacenar el estado de arranque

// variables a ocupar en el modulo 0
bool and0;
bool or0;
bool S0;
bool R0;
bool Q0;
bool D0;

//variables a ocupar en el modulo 1
bool and1;
bool or1;
bool S1;
bool R1;
bool Q1;

//variables a ocupar en el mod 2
bool and2;
bool or2;
bool S2;
bool R2;
bool Q2;

//variables a ocupar en el mod 3
bool and3;
bool or3;
bool S3;
bool R3;
bool Q3;

//variables a ocupar en el mod 4
bool and4;
bool or4;
bool S4;
bool R4;
bool Q4;

//variables a ocupar en el mod 5
bool and5;
bool or5;
bool S5;
bool R5;
bool Q5;

//variables a ocupar en el mod 6
bool and6;
bool or6;
bool S6;
bool R6;
bool Q6;

//variables a ocupar en el mod 7
bool and7;
bool or7;
bool S7;
bool R7;
bool Q7;

//variables a ocupar en el mod 8
bool and8;
bool or8;
bool S8;
bool R8;
bool Q8;

//variables a ocupar en el mod 9
bool and9;
bool or9;
bool S9;
bool R9;
bool Q9;

//variables a ocupar en el mod 10
bool and10;
bool or10;
bool S10;
bool R10;
bool Q10;

//variables a ocupar en el mod 11
bool and11;
bool or11;
bool S11;
bool R11;
bool Q11;

//variables a ocupar en el mod 12
bool and12;
bool or12;
bool S12;
bool R12;
bool Q12;

//variables a ocupar en el mod 13
bool and13;
bool or13;
bool S13;
bool R13;
bool Q13;

void setup() {
  // Pines para salidas
  pinMode(MotDerFrePin, OUTPUT);  //
  pinMode(MotDerRevPin, OUTPUT);  //
  pinMode(MotIzqFrePin, OUTPUT);  //
  pinMode(MotIzqRevPin, OUTPUT);  //

  estadoArranque = true;  //  se pone en el setup para que solo se cargue una vez

  //////////
  Serial.begin(9600);
  pinMode(FRONT_TRIG_PIN, OUTPUT);
  pinMode(FRONT_ECHO_PIN, INPUT);
  pinMode(RIGHT_TRIG_PIN, OUTPUT);
  pinMode(RIGHT_ECHO_PIN, INPUT);
  pinMode(LEFT_TRIG_PIN, OUTPUT);
  pinMode(LEFT_ECHO_PIN, INPUT);
  pinMode(BACK_TRIG_PIN, OUTPUT);
  pinMode(BACK_ECHO_PIN, INPUT);
  pinMode(CAPACITIVE_SENSOR_PIN, INPUT);
  //////////
}

void loop() {

  ////////////////
  int frontResult = checkUltrasonicSensorF(FRONT_TRIG_PIN, FRONT_ECHO_PIN);
  int rightResult = checkUltrasonicSensorR(RIGHT_TRIG_PIN, RIGHT_ECHO_PIN);
  int leftResult = checkUltrasonicSensorL(LEFT_TRIG_PIN, LEFT_ECHO_PIN);
  int backResult = checkUltrasonicSensorB(BACK_TRIG_PIN, BACK_ECHO_PIN);
  int capacitiveResult = checkCapacitiveSensor(CAPACITIVE_SENSOR_PIN);

  Serial.print("Front: ");
  Serial.print(frontResult);
  Serial.print(" Right: ");
  Serial.print(rightResult);
  Serial.print(" Left: ");
  Serial.print(leftResult);
  Serial.print(" Back: ");
  Serial.print(backResult);
  Serial.print(" Capacitive: ");
  Serial.println(capacitiveResult);

static unsigned long lastMillis = 0;
const unsigned long interval = 300;  // intervalo en milisegundos

if (millis() - lastMillis >= interval) {
  // Tu código aquí
  lastMillis = millis();  // Reinicia el temporizador
}
  //delay(300);  // Pausa de 1 segundo entre lecturas
  ////////////////
  estadofre = frontResult ;
  estadoder = rightResult;
  estadoizq = leftResult;  //leer los estados de los sensores
  estadoatr = backResult;
  estadoaba = capacitiveResult;
  ////////////////
  //Izquierda || Derecha retroceden
  //bool CX = ((estadoder && estadoizq && !estadoatr && !estadoaba)||(estadofre && estadoder && estadoizq && !estadoatr));
  //Izquierda avanza
  bool C1 = (!estadoder||(!estadofre && estadoaba)); 
  //Derecha avanza
  bool C2 = ((!estadofre && estadoaba)||(estadoder && !estadoizq));
  //Izquierda retrocede
  bool C3 = ((estadofre && estadoder && !estadoizq)||(estadoder && !estadoizq && !estadoaba)||(estadoder && !estadoatr && !estadoaba)||(estadofre && estadoder && !estadoatr));
  //Derecha retrocede
  bool C4 = ((estadoizq && !estadoatr && !estadoaba)||(estadofre && estadoizq && !estadoaba)||(estadofre && !estadoder)||(!estadoder&&!estadoaba));

  if (millis() - lastMillis >= interval) {
  // Tu código aquí
  lastMillis = millis();  // Reinicia el temporizador
}
  //MODULO CERO 
  and0 = estadoArranque && true;           //la AND de modulo 0 recibe una activacion llamada A que definimos previamente en el setup y un true (1)
  or0 = estadoParo || (Q1 || Q2);        //el paro de emergencia o el cumplimiento de la compuerta OR de las etapas 1 y 2 desactivara este modulo 0
  R0 = or0;                      //la entrada Reset del flipflop es la salida de la compuerta OR
  S0 = and0;                        //la entrada SET del flipflop es la salida de AND
  if (S0 && !R0) {                  //esto es del flipflop rs
    Q0 = true;  // SET activo       //esto es del flipflop rs
  } else if (!S0 && R0) {           //esto es del flipflop rs
    Q0 = false;  // RESET activo    //esto es del flipflop rs
  }
    D0 = Q0;            //se le asigna a D0 el valor de la salida del flipflop
  //sin accion

//MODULO UNO
  and1 = Q0 && true;   //la AND de modulo 1 recibe la salida del flipflop del mod0 y un true (1)
  or1 = estadoParo || (Q3 || Q4); //el paro de emergencia o el cumplimiento de la etapa 3 o 4 desactivara este modulo 0
  R1 = or1;                     //la entrada Reset del flipflop es la salida de la compuerta OR
  S1 = and1;                   //la entrada S del flipflop es la salida de la compuerta AND
  if (S1 && !R1) {              //esto es del flipflop rs
    Q1 = true;  // SET activo   //esto es del flipflop rs
  } else if (!S1 && R1) {       //esto es del flipflop rs
    Q1 = false;  // RESET activo  //esto es del flipflop rs
  }
  //sin accion

  //MODULO DOS
  and2 = Q0 && true;   //la AND del modulo 2 recibe la salida del flipflop del mod0 y un true (1)
  or2 = estadoParo || (Q5 || Q6);   //el paro de emergencia o el cumplimiento del modulo 5 o 6 desactivara la etapa 1
  R2 = or2;                     //la entrada Reset del flipflop es la salida de la compuerta OR
  S2 = and2;                   //la entrada S del flipflop es la salida de la compuerta AND
  if (S2 && !R2) {              //esto es del flipflop rs
    Q2 = true;  // SET activo   //esto es del flipflop rs
  } else if (!S2 && R2) {       //esto es del flipflop rs
    Q2 = false;  // RESET activo  //esto es del flipflop rs
  }
  
  //MODULO TRES
  and3 = Q1 && C1;   //la AND del modulo 3 recibe la salida del flipflop del modulo 1 (Q1) y la ecuacion que satisfaga encender el motor izquierdo hacia enfrente
  or3 = estadoParo || Q7;            //el paro de mergencia o el cumplimiento del modulo 7 desactivara este modulo 3
  R3 = or3;                     //la entrada Reset del flipflop es la salida de la compuerta OR
  S3 = and3;                   //la entrada S del flipflop es la salida de la compuerta AND
  if (S3 && !R3) {              //esto es del flipflop rs
    Q3 = true;  // SET activo   //esto es del flipflop rs
  } else if (!S3 && R3) {       //esto es del flipflop rs
    Q3 = false;  // RESET activo  //esto es del flipflop rs
  }
  digitalWrite(MotIzqFrePin, Q3);  // Activa el motor izquierdo para enfrente según el valor de Q3
  
//MODULO CUATRO
  and4 = Q1 && C3;  //la AND del modulo 4 recibe la salida del fliflop del modulo 1 (Q1) y la ecuacion que satisfaga encender el motor izquierdo en reversa
  or4 = estadoParo || Q8;            //el paro de emergencia o el cumplimiento del modulo 7 desactivara este modulo 4
  R4 = or4;                     //la entrada Reset del flipflop es la salida de la compuerta OR
  S4 = and4;                   //la entrada S del flipflop es la salida de la compuerta AND
  if (S4 && !R4) {              //esto es del flipflop rs
    Q4 = true;  // SET activo   //esto es del flipflop rs
  } else if (!S4 && R4) {       //esto es del flipflop rs
    Q4 = false;  // RESET activo  //esto es del flipflop rs
  }
  digitalWrite(MotIzqRevPin, Q4);  // Activa el motor izquierdo en reversa según el valor de Q4
  
  //MODULO CINCO
  and5 = Q2 && C2;   //la AND del modulo 5 recibe la salida del fliflop del modulo 2 (Q2) y la ecuacion que satisfaga encender el motor derecho hacia enfrente
  or5 = estadoParo || Q9;            //el paro de mergencia o el cumplimiento del modulo 8 desactivara este modulo 5
  R5 = or5;                     //la entrada Reset del flipflop es la salida de la compuerta OR
  S5 = and5;                   //la entrada S del flipflop es la salida de la compuerta AND
  if (S5 && !R5) {              //esto es del flipflop rs
    Q5 = true;  // SET activo   //esto es del flipflop rs
  } else if (!S5 && R5) {       //esto es del flipflop rs
    Q5 = false;  // RESET activo  //esto es del flipflop rs
  }
  digitalWrite(MotDerFrePin, Q5);  // Activa el motor derecho hacia enfrente según el valor de Q5

  //MODULO SEIS
  and6 = Q2 && C4;   //la AND del modulo 6 recibe la salida del fliflop del modulo 2 (Q2) y la ecuacion que satisfaga encender el motor derecho en reversa
  or6 = estadoParo || Q10;            //el paro de mergencia o el cumplimiento del modulo 8 desactivara este modulo 6
  R6 = or6;                     //la entrada Reset del flipflop es la salida de la compuerta OR
  S6 = and6;                   //la entrada S del flipflop es la salida de la compuerta AND
  if (S6 && !R6) {              //esto es del flipflop rs
    Q6 = true;  // SET activo   //esto es del flipflop rs
  } else if (!S6 && R6) {       //esto es del flipflop rs
    Q6 = false;  // RESET activo  //esto es del flipflop rs
  }
  digitalWrite(MotDerRevPin, Q6);  // Activa el motor derecho DE REVERSA según el valor de Q6
  
  //MODULO SIETE
  and7 = Q3 && !C1;//la AND del modulo 7 recibe Q3 y la condicion de no cumplimiento de la ecuacion de entrada de mod3
  or7 = estadoParo || Q11;            //el paro de mergencia o el cumplimiento del mod 0 desactivara este modulo 7                                                                        
  R7 = or7;                     //la entrada Reset del flipflop es la salida de la compuerta OR
  S7 = and7;                   //la entrada S del flipflop es la salida de la compuerta AND
  if (S7 && !R7) {              //esto es del flipflop rs
    Q7 = true;  // SET activo   //esto es del flipflop rs
  } else if (!S7 && R7) {       //esto es del flipflop rs
    Q7 = false;  // RESET activo  //esto es del flipflop rs
  }
  //sin accion ya que por si solo desactiva las etapas donde el motor se enciende    

//MODULO OCHO
  and8 = Q4 && !C3;   ////la AND del modulo 8 recibe el resultado de una or entre las salidas del modulo 5 y 6 
  or8 = estadoParo || Q11;            //el paro de mergencia o el cumplimiento del modulo 0 desactivara este modulo 8
  R8 = or8;                     //la entrada Reset del flipflop es la salida de la compuerta OR
  S8 = and8;                   //la entrada S del flipflop es la salida de la compuerta AND
  if (S8 && !R8) {              //esto es del flipflop rs
    Q8 = true;  // SET activo   //esto es del flipflop rs
  } else if (!S8 && R8) {       //esto es del flipflop rs
    Q8 = false;  // RESET activo  //esto es del flipflop rs      
  }

//MODULO NUEVE
  and9 = Q5 && !C2;   //la AND del modulo 3 recibe la salida del flipflop del modulo 1 (Q1) y la ecuacion que satisfaga encender el motor izquierdo hacia enfrente
  or9 = estadoParo || Q12;            //el paro de mergencia o el cumplimiento del modulo 7 desactivara este modulo 3
  R9 = or9;                     //la entrada Reset del flipflop es la salida de la compuerta OR
  S9 = and9;                   //la entrada S del flipflop es la salida de la compuerta AND
  if (S9 && !R9) {              //esto es del flipflop rs
    Q9 = true;  // SET activo   //esto es del flipflop rs
  } else if (!S9 && R9) {       //esto es del flipflop rs
    Q9 = false;  // RESET activo  //esto es del flipflop rs
  }

  //MODULO DIEZ
  and10 = Q6 && !C4;   //la AND del modulo 3 recibe la salida del flipflop del modulo 1 (Q1) y la ecuacion que satisfaga encender el motor izquierdo hacia enfrente
  or10 = estadoParo || Q12;            //el paro de mergencia o el cumplimiento del modulo 7 desactivara este modulo 3
  R10 = or10;                     //la entrada Reset del flipflop es la salida de la compuerta OR
  S10 = and10;                   //la entrada S del flipflop es la salida de la compuerta AND
  if (S10 && !R10) {              //esto es del flipflop rs
    Q10 = true;  // SET activo   //esto es del flipflop rs
  } else if (!S10 && R10) {       //esto es del flipflop rs
    Q10 = false;  // RESET activo  //esto es del flipflop rs
  }

  //MODULO ONCE
  and11 = (Q7 || Q8) && true;   //la AND del modulo 3 recibe la salida del flipflop del modulo 1 (Q1) y la ecuacion que satisfaga encender el motor izquierdo hacia enfrente
  or11 = estadoParo || Q13;            //el paro de mergencia o el cumplimiento del modulo 7 desactivara este modulo 3
  R11 = or1;                     //la entrada Reset del flipflop es la salida de la compuerta OR
  S11 = and11;                   //la entrada S del flipflop es la salida de la compuerta AND
  if (S11 && !R11) {              //esto es del flipflop rs
    Q11 = true;  // SET activo   //esto es del flipflop rs
  } else if (!S11 && R11) {       //esto es del flipflop rs
    Q11 = false;  // RESET activo  //esto es del flipflop rs
  }

  //MODULO DOCE
  and12 = (Q9 || Q10) && true;   //la AND del modulo 3 recibe la salida del flipflop del modulo 1 (Q1) y la ecuacion que satisfaga encender el motor izquierdo hacia enfrente
  or12 = estadoParo || Q13;            //el paro de mergencia o el cumplimiento del modulo 7 desactivara este modulo 3
  R12 = or12;                     //la entrada Reset del flipflop es la salida de la compuerta OR
  S12 = and12;                   //la entrada S del flipflop es la salida de la compuerta AND
  if (S12 && !R12) {              //esto es del flipflop rs
    Q12 = true;  // SET activo   //esto es del flipflop rs
  } else if (!S12 && R12) {       //esto es del flipflop rs
    Q12 = false;  // RESET activo  //esto es del flipflop rs
  }

  //MODULO TRECE
  and13 = (Q11 || Q12) && true;   //la AND del modulo 3 recibe la salida del flipflop del modulo 1 (Q1) y la ecuacion que satisfaga encender el motor izquierdo hacia enfrente
  or13 = estadoParo || D0;            //el paro de mergencia o el cumplimiento del modulo 7 desactivara este modulo 3
  R13 = or13;                     //la entrada Reset del flipflop es la salida de la compuerta OR
  S13 = and13;                   //la entrada S del flipflop es la salida de la compuerta AND
  if (S13 && !R13) {              //esto es del flipflop rs
    Q13 = true;  // SET activo   //esto es del flipflop rs
  } else if (!S13 && R13) {       //esto es del flipflop rs
    Q13 = false;  // RESET activo  //esto es del flipflop rs
  }
  estadoArranque = Q13;

}

int checkUltrasonicSensorF(int trigPin, int echoPin) {
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);          //Enviamos un pulso de 10us
  digitalWrite(trigPin, LOW);
  t = pulseIn(echoPin, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(2000);         
  Serial.println("Velocidad:");
  Serial.println(d/t);
  return (d <= 400) ? 1 : 0;
}
int checkUltrasonicSensorB(int trigPin, int echoPin) {
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);          //Enviamos un pulso de 10us
  digitalWrite(trigPin, LOW);
  t = pulseIn(echoPin, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  delay(10);          //Hacemos una pausa de 100ms
  return (d <= 40) ? 1 : 0;
}
int checkUltrasonicSensorR(int trigPin, int echoPin) {
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);          //Enviamos un pulso de 10us
  digitalWrite(trigPin, LOW);
  t = pulseIn(echoPin, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  delay(10);          //Hacemos una pausa de 100ms
  return (d <= 40) ? 1 : 0;
}

int checkUltrasonicSensorL(int trigPin, int echoPin) {
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);          //Enviamos un pulso de 10us
  digitalWrite(trigPin, LOW);
  t = pulseIn(echoPin, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  delay(10);          //Hacemos una pausa de 100ms
  return (d <= 40) ? 1 : 0;
}

int checkCapacitiveSensor(int pin) {
  int sensorValue = digitalRead(pin);
  return (sensorValue == HIGH) ? 0 : 1;
}