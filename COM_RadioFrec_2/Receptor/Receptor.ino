//Receptor

#include <RH_ASK.h>    // Incluye la biblioteca RH_ASK para la comunicación inalámbrica
#include <SPI.h>       // Incluye la biblioteca SPI para la comunicación con el módulo de radiofrecuencia

RH_ASK rf_driver;      // Crea una instancia del objeto RH_ASK para la comunicación RF

#define LEDROJO 2      // Define el pin para el LED rojo como 2
#define LEDVERDE 3     // Define el pin para el LED verde como 3

void setup() {
  pinMode(LEDROJO, OUTPUT);      // Configura el pin del LED rojo como salida
  pinMode(LEDVERDE, OUTPUT);     // Configura el pin del LED verde como salida
  rf_driver.init();              // Inicializa la comunicación RF
}

void loop() {
  uint8_t buf[1];                // Crea un arreglo de 1 byte para almacenar el mensaje recibido
  uint8_t buflen = sizeof(buf);  // Obtiene el tamaño del arreglo de bytes

  if (rf_driver.recv(buf, &buflen)) {    // Recibe un mensaje y verifica si se recibió correctamente
    if ((char)buf[0] == '1') {           // Verifica si el mensaje recibido es '1'
      digitalWrite(LEDROJO, !digitalRead(LEDROJO));   // Cambia el estado del LED rojo
    } else if ((char)buf[0] == '2') {     // Verifica si el mensaje recibido es '2'
      digitalWrite(LEDVERDE, HIGH);      // Enciende el LED verde
      delay(5000);                       // Espera 5 segundos
      digitalWrite(LEDVERDE, LOW);       // Apaga el LED verde
    }
  }
}
