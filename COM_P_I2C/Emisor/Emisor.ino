//Emisor

#include<Wire.h> //Biblioteca que proporciona las funciones necesarias para la comunicación I2C.

void setup() {
  Wire.begin(1);  // Establece que el emisor estará utilizando el canal 1 (0x01).
  Wire.onRequest(peticion);  //Creamos el evento que se realizará cuando el receptor llame al emisor(Este arduino)
  Serial.begin(9600);
}

void loop() {
}

void peticion()
{
  Serial.println("Se pidio el mensaje enviado"); //Imprimimos cuando el receptor nos pide el mensaje
  Wire.write("Hola soy el canal 1"); //: Envía la cadena de texto "Hola soy el canal 1" (19 caracteres) al receptor a través del bus I2C
}
