/*lectura de sensores, usando las entradas analogicas
   Tarjeta SD conectada al bus SPI de la siguiente manera:
 * * MOSI - pin 11
 * * MISO - pin 12
 * * SCK - pin13
 * * CS - pin4 */

#include<SD.h>

File myFile;

void setup() {
  Serial.begin(9600);
  Serial.print("Iniciando SD...");
    if (!SD.begin(4)) {
    Serial.println("No se puede inicializar");
    return;
  }
  Serial.println("Inicializacion exitosa");
}

void loop() {
  myFile = SD.open("Sensores.txt", FILE_WRITE); //Abrimos el archivo
  if (myFile) {
    Serial.print("Escribiendo SD: ");
    int sensor1 = analogRead(0);
    int sensor2 = analogRead(1);
    int sensor3 = analogRead(2);

    //myFile.print("Tiempo(ms)=");
    myFile.print(millis());
    myFile.print(", sensor1=");
    myFile.print(sensor1);
    myFile.print(", sensor2=");
    myFile.print(sensor2);
    myFile.print(", sensor3=");
    myFile.println(sensor3);
    myFile.close(); //Cerramos el archivo

    //myFile.print("Tiempo(ms)=");
    Serial.print(millis());
    Serial.print(", sensor1=");
    Serial.print(sensor1);
    Serial.print(", sensor2=");
    Serial.print(sensor2);
    Serial.print(", sensor3=");
    Serial.println(sensor3);
  } else {
    Serial.println("Error al abrir el archivo");
  }

}
