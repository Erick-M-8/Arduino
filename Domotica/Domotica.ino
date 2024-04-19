#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(10, 5, 208, 35);
EthernetServer servidor(80);

int PIN_LED1 = 8;
int PIN_LED2 = 9;
int PIN_LED3 = 7;
int PIN_SENSOR1 = 2;
int PIN_SENSOR2 = A1;
int PIN_SENSOR3 = 4;
int PIN_SENSOR4 = 5;
int PIN_BOMBA = 6;
int PIN_SENSOR_TEMP = A0;
int PIN_VENTILADOR = 3;
int PIN_CALENTADOR = A5;
String readString = String(30);
String state1 = String(3);
String state2 = String(3);
String state3 = String(3);
String stateBomba = String(3);
String stateVentilador = String(3);
String stateCalentador = String(3);

void setup() {
  Ethernet.begin(mac, ip);
  servidor.begin();
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
  pinMode(PIN_SENSOR1, INPUT);
  pinMode(PIN_SENSOR2, INPUT);
  pinMode(PIN_SENSOR3, INPUT);
  pinMode(PIN_SENSOR4, INPUT);
  pinMode(PIN_BOMBA, OUTPUT);
  pinMode(PIN_SENSOR_TEMP, INPUT);
  pinMode(PIN_VENTILADOR, OUTPUT);
  pinMode(PIN_CALENTADOR, OUTPUT);
  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED2, LOW);
  digitalWrite(PIN_LED3, LOW);
  digitalWrite(PIN_BOMBA, LOW);
  digitalWrite(PIN_VENTILADOR, LOW);
  digitalWrite(PIN_CALENTADOR, LOW);
  state1 = "OFF";
  state2 = "OFF";
  state3 = "OFF";
  stateBomba = "OFF";
  stateVentilador = "OFF";
  stateCalentador = "OFF";
}

void loop() {
  EthernetClient cliente = servidor.available();
  if (cliente) {
    Serial.println("new client");
    boolean lineaenblanco = true;
    while (cliente.connected()) {
      if (cliente.available()) {
        char c = cliente.read();
        if (readString.length() < 30) {
          readString.concat(c);
        }

        if (c == '\n' && lineaenblanco) {
          int LED1 = readString.indexOf("LED1=");
          int LED2 = readString.indexOf("LED2=");
          int LED3 = readString.indexOf("LED3=");
          if (readString.substring(LED1, LED1 + 6) == "LED1=T") {
            digitalWrite(PIN_LED1, HIGH);
            state1 = "ON";
          } else if (readString.substring(LED1, LED1 + 6) == "LED1=F") {
            digitalWrite(PIN_LED1, LOW);
            state1 = "OFF";
          }

          if (readString.substring(LED2, LED2 + 6) == "LED2=T") {
            digitalWrite(PIN_LED2, HIGH);
            state2 = "ON";
          } else if (readString.substring(LED2, LED2 + 6) == "LED2=F") {
            digitalWrite(PIN_LED2, LOW);
            state2 = "OFF";
          }

          if (readString.substring(LED3, LED3 + 6) == "LED3=T") {
            digitalWrite(PIN_LED3, HIGH);
            state3 = "ON";
          } else if (readString.substring(LED3, LED3 + 6) == "LED3=F") {
            digitalWrite(PIN_LED3, LOW);
            state3 = "OFF";
          }

          if (digitalRead(PIN_SENSOR2) == HIGH && digitalRead(PIN_SENSOR3) == LOW && digitalRead(PIN_SENSOR4) == LOW) {
            digitalWrite(PIN_BOMBA, HIGH);
            stateBomba = "ON";
          } else if (digitalRead(PIN_SENSOR2) == HIGH && digitalRead(PIN_SENSOR3) == HIGH && digitalRead(PIN_SENSOR4) == LOW) {
            digitalWrite(PIN_BOMBA, HIGH);
            stateBomba = "ON";
          }else{
            digitalWrite(PIN_BOMBA, LOW);
            stateBomba = "OFF";
          }

          int temperatura = obtenerTemperatura();
          if (temperatura > 26) {
            digitalWrite(PIN_VENTILADOR, HIGH);
            digitalWrite(PIN_CALENTADOR, LOW);
            stateVentilador = "ON";
            stateCalentador = "OFF";
          } else if (temperatura < 15) {
            digitalWrite(PIN_VENTILADOR, LOW);
            digitalWrite(PIN_CALENTADOR, HIGH);
            stateVentilador = "OFF";
            stateCalentador = "ON";
          } else {
            digitalWrite(PIN_VENTILADOR, LOW);
            digitalWrite(PIN_CALENTADOR, LOW);
            stateVentilador = "OFF";
            stateCalentador = "OFF";
          }

          cliente.println("HTTP/1.1 200 OK");
          cliente.println("Content-Type: text/html");
          cliente.println();
          cliente.println("<html>");
          cliente.println("<head>");
          cliente.println("<title>LED ON/OFF</title>");
          cliente.println("</head>");
          cliente.println("<body width=100% height=100%>");
          cliente.println("<center>");
          cliente.println("<h1>LED ON/OFF</h1>");
          cliente.println("<br><br>");
          cliente.println("Estado del LED 1: ");
          cliente.println(state1);
          cliente.println("<br><br>");
          cliente.println("Estado del LED 2: ");
          cliente.println(state2);
          cliente.println("<br><br>");
          cliente.println("Estado del LED 3: ");
          cliente.println(state3);
          cliente.println("<br><br>");
          cliente.println("Estado de la bomba: ");
          cliente.println(stateBomba);
          cliente.println("<br><br>");
          cliente.println("Temperatura: ");
          cliente.println(temperatura);
          cliente.println("°C");
          cliente.println("<br><br>");
          cliente.println("Estado del ventilador: ");
          cliente.println(stateVentilador);
          cliente.println("<br><br>");
          cliente.println("Estado del calentador: ");
          cliente.println(stateCalentador);
          cliente.println("<br><br>");

          cliente.println("Estado del Sensor 1: ");
          cliente.println(obtenerEstadoSensor(PIN_SENSOR1));
          cliente.println("<br><br>");
          cliente.println("Estado del Sensor 2: ");
          cliente.println(obtenerEstadoSensor(PIN_SENSOR2));
          cliente.println("<br><br>");
          cliente.println("Estado del Sensor 3: ");
          cliente.println(obtenerEstadoSensor(PIN_SENSOR3));
          cliente.println("<br><br>");
          cliente.println("Estado del Sensor 4: ");
          cliente.println(obtenerEstadoSensor(PIN_SENSOR4));

          cliente.println("<br><br><br><br>");
          cliente.println("<input type=submit value=ON style=width:200px; heigth:75px onClick=location.href='./LED1=T\'>");
          cliente.println("<input type=submit value=OFF style=width:200px; heigth:75px onClick=location.href='./LED1=F\'>");
          cliente.println("<br><br>");
          cliente.println("<input type=submit value=ON style=width:200px; heigth:75px onClick=location.href='./LED2=T\'>");
          cliente.println("<input type=submit value=OFF style=width:200px; heigth:75px onClick=location.href='./LED2=F\'>");
          cliente.println("<br><br>");
          cliente.println("<input type=submit value=ON style=width:200px; heigth:75px onClick=location.href='./LED3=T\'>");
          cliente.println("<input type=submit value=OFF style=width:200px; heigth:75px onClick=location.href='./LED3=F\'>");
          cliente.println("</center>");
          cliente.println("</body>");
          cliente.println("</html>");
          cliente.stop();
          readString = "";
        }
      }
    }
  }
}

int obtenerTemperatura() {
  int lectura = analogRead(PIN_SENSOR_TEMP);
  float voltage = (lectura / 1024.0) * 5.0;
  float temperaturaC = (voltage - 0.5) * 100.0;
  return (int)temperaturaC;
}

String obtenerEstadoSensor(int pin) {
  int valor = digitalRead(pin);
  if (valor == HIGH) {
    return "ACTIVO";
  } else {
    return "INACTIVO";
  }
}
