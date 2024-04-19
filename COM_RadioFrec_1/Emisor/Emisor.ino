//Emisor
//Pin 12: MISO (Master In Slave Out)

#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_driver;

void setup() {
  rf_driver.init();  // Inicializa la comunicación RF
}

void loop() {
  const char msg[] = "Hola desde lejos";  // Define el mensaje a enviar
  rf_driver.send((uint8_t *)msg, strlen(msg));  // Envía el mensaje (puntero al mensaje, longitud del mensaje  en bytes)
  rf_driver.waitPacketSent();  // Espera a que el paquete se envíe completamente
  delay(1000);  // Espera 1 segundo antes de enviar el siguiente mensaje.
}
