/*Comunicación bilateral (Se envia y reciben datos entre el monitor serial y el Arduino)
La computadora envia el mensaje hola o adios al arduino, este respondera según el mensaje*/

String inputString = "";  // Variable para almacenar la cadena recibida
bool stringComplete = false;  // Indica si se ha recibido una cadena completa

void setup() {
  Serial.begin(9600);  // Iniciar comunicación serial a 9600 bps
}

void loop() {
   // Leer desde el monitor serial si hay datos disponibles
  if (Serial.available()>0) { 
    char receivedChar = Serial.read();  // Leer el siguiente carácter disponible
    if (receivedChar == '\n') {  // Si se recibe el carácter de nueva línea
      stringComplete = true;  // Marcar que se ha recibido una cadena completa
    } else {
      inputString += receivedChar;  // Agregar el carácter a la cadena
    }
  }

  // Procesar la cadena si se ha recibido completa
  if (stringComplete) {
    Serial.print("Cadena recibida: ");
    Serial.println(inputString);

    // Enviar respuesta al monitor serial basada en la cadena recibida
    if (inputString == "Hola") {
      Serial.println("Hola desde Arduino!");
    } else if (inputString == "Adios") {
      Serial.println("Adiós desde Arduino!");
    } else {
      Serial.println("Comando inválido");
    }

    // Reiniciar variables para recibir una nueva cadena
    inputString = "";
    stringComplete = false;
  }
}

