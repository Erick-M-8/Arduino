//Receptor
//Pin 11: MOSI (Master Out Slave In)
#include <RH_ASK.h>  // Incluye la biblioteca RH_ASK para la comunicación inalámbrica
#include <SPI.h>     // Incluye la biblioteca SPI para la comunicación con el módulo de radiofrecuencia

RH_ASK rf_driver;    // Crea una instancia del objeto RH_ASK para la comunicación RF

void setup() {
  rf_driver.init();               // Inicializa la comunicación RF
  Serial.begin(9600);             // Inicia la comunicación serie (Serial) a 9600 baudios
}

void loop() {
  uint8_t buf[16];                // Crea un arreglo de 16 elementos de tipo uint8_t para almacenar el mensaje recibido
  uint8_t buflen = sizeof(buf);   // Obtiene el tamaño del arreglo de bytes (=17)

  if (rf_driver.recv(buf, &buflen)) {  // Recibe un mensaje y verifica si se recibió correctamente
    Serial.print("Mensaje: ");         // Imprime el texto "Mensaje: "
    Serial.println((char*)buf);        // Convierte los bytes a una cadena de caracteres y la imprime por el puerto serie,  Al pasar (char*)buf como argumento, se interpreta el contenido del arreglo buf como una cadena de caracteres y se imprime en su totalidad.
  }
}
