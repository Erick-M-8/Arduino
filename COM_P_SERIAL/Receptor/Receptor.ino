//Receptor

String mensajeRecibido;
bool mensajeCompleto = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()>0){
    char caracter = Serial.read();
    if( caracter == '\n'){
      mensajeCompleto= true;
    }else{
      mensajeRecibido += caracter;
    }
  }

  if(mensajeCompleto){
    if(mensajeRecibido == "Hola"){
      Serial.println("Hola soy el receptor");
    }else
    if(mensajeRecibido == "Adios"){
      Serial.println("Adios emisor");
    }
    mensajeRecibido = "";
    mensajeCompleto = false;
  }
}
