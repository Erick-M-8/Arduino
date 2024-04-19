/**/
#include <SPI.h> //Aqui incluimos la libreria SPI
#include <Ethernet.h> //Aqui incluimos la libreria Ethernet

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}; //Declaracion de de la dirección MAC
IPAddress ip(10, 5, 208, 37); //Declaracion de la IP laboratorio 5
EthernetServer servidor(80); //Declaracion del puerto 80

int PIN_LED = 8; //Aquiu establecemos la variable PIN_LED como un valor entero
              String readString = String(30); //Lee los caracteres de una secuencia en una cadena
//Los strings se representan como arrays de caracteres (tipo char)
String state = String(3);

void setup() {
  Ethernet.begin(mac, ip); //Inicializamos con las direcciones asignadas
  servidor.begin(); //Inicia el servidor
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
  state = "OFF";
}

void loop() {
  //EthernetClient Crea un cliente que se puede conectar
  //una direccion especifica de internet IP
  EthernetClient cliente = servidor.available();
  if (cliente) {
    boolean lineaenblanco = true;
    while (cliente.connected()) {
      if (cliente.available()) { //Sie el cliente esta disponible
        char c = cliente.read();
        if (readString.length() < 30) {
          readString.concat(c); //leer cadena
          //Cliente conectado
          //Leemos peticion HTTP caracter a caracter
          //Almacenar los caracteres en la variable de readString
        }
        if (c == '\n' && lineaenblanco) { //Si la peticion HTTP ha finalizado
          int LED = readString.indexOf("LED="); //Leer cadena
          if (readString.substring(LED, LED + 5) == "LED=T") {
            digitalWrite(PIN_LED, HIGH);
            state = "ON";
          } else if (readString.substring(LED, LED + 5) == "LED=F") {
            digitalWrite(PIN_LED, LOW);
            state = "OFF";
          }
          //Cabecera HTTP estándar
          cliente.println("HTTP/1.1 200 OK");
          cliente.println("Content-Type: text/html");
          cliente.println(); //Pagina web en HTML
          cliente.println("<html>");
          cliente.println("<head>");
          cliente.println("<title> LED ON/OFF </title>");
          cliente.println("</head>");
          cliente.println("<body width=100% height=100%>");
          cliente.println("<center>");
          cliente.println("<h1> LED ON/OFF</h1>");
          cliente.println("<br><br>");
          cliente.println("Estado del LED:");
          cliente.println(state);
          cliente.println("<br><br><br><br>");
          cliente.println("<input type = submit value = ON style = width: 200px:  height: 75px onclick=location.href='./?LED=T\'>");
          cliente.println("<input type = submit value = OFF style = width: 200px:  height: 75px onclick=location.href='./?LED=F\'>");
          cliente.println("</center>");
          cliente.println("</body>");
          cliente.println("</html>");
          cliente.stop();
          //Cierre de la conexion con el cliente
          readString = "";

        }
      }
    }
  }
}
