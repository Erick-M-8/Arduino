// Emisor

#include <RH_ASK.h>   // Incluye la librería RadioHead.h
#include <SPI.h>      // Incluye la librería SPI necesaria para RadioHead.h

RH_ASK rf_driver;    // Crea un objeto para la modulación por ASK

#define PULSADOR1 2   // Define el pin del primer pulsador como 2
#define PULSADOR2 3   // Define el pin del segundo pulsador como 3

void setup() {
  pinMode(PULSADOR1, INPUT_PULLUP);   // Configura el pin del primer pulsador como entrada con pull-up interno
  pinMode(PULSADOR2, INPUT_PULLUP);   // Configura el pin del segundo pulsador como entrada con pull-up interno
  rf_driver.init();                   // Inicializa la comunicación RF
}

void loop() {
  if (digitalRead(PULSADOR1) == LOW) {    // Verifica si se presionó el primer pulsador
    const char *msg = "1";                // Define el mensaje a enviar como "1"
    rf_driver.send((uint8_t *)msg, strlen(msg));   // Envía el mensaje
    rf_driver.waitPacketSent();                     // Espera a que se envíe el paquete
  }
  else if (digitalRead(PULSADOR2) == LOW) {   // Verifica si se presionó el segundo pulsador
    const char *msg = "2";                    // Define el mensaje a enviar como "2"
    rf_driver.send((uint8_t *)msg, strlen(msg));   // Envía el mensaje
    rf_driver.waitPacketSent();                     // Espera a que se envíe el paquete
  }
  delay(200);   // Espera un tiempo para evitar rebotes o múltiples envíos
}

