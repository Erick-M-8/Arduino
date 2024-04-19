//Receptor

#include <Wire.h>
char mensaje;

void setup() {
  Wire.begin();        // Iniciar la comunicación I2C en el canal 0 (0x00)
  Serial.begin(9600);  // Iniciamos el monitor serial para mostrar los mensajes
}

void loop() {
  if (Serial.available()) {               // Verifica si existe un byte de entrada desde el monitor serial
    char valor = Serial.read();           // Leer el carácter disponible desde el monitor serial
    if (valor == 'a') {
      Wire.requestFrom(1, 19);           // Realizar una petición al canal 1 de 19 caracteres (bytes)
      Serial.println("Mensaje pedido");  // Imprimir que se ha pedido el mensaje al emisor
    }
  }

  while (Wire.available()) { //Verificar si hay bytes (caracteres) disponibles para ser leídos desde el bus I2C
    mensaje = Wire.read();  // Lee el siguiente caracter (byte) de datos disponible del búfer de recepción y lo guarda en la variable 'mensaje' de tipo char.
    Serial.print(mensaje);  // Imprimir el mensaje (Se imprime byte por byte)
    delay(100);
  }
  delay(2500);
}

