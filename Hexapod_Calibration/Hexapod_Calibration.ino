/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com  
*********/

// Load Wi-Fi library
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Replace with your network credentials
const char* ssid = "Tito - cel";
const char* password = "teste123";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output26State = "off";
String output27State = "off";
String output28State = "off";
String output29State = "off";
String output30State = "off";

// INSTANCIANDO OBJETOS
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// DECLARAÇÃO DE FUNÇÕES
void writeServos(int posicao, int tempo);
void beginServos();

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);



  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();

  beginServos();  // INCIA OS SERVOS
  delay(300);
}

void loop() {
  WiFiClient client = server.available();  // Listen for incoming clients

  if (client) {  // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");                                             // print a message out in the serial port
    String currentLine = "";                                                   // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {  // if there's bytes to read from the client,
        char c = client.read();  // read a byte, then
        Serial.write(c);         // print it out the serial monitor
        header += c;
        if (c == '\n') {  // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            //_______________________________________________________________________________________________________________

            // BOTÃO 1

            //_______________________________________________________________________________________________________________


            // turns the GPIOs on and off
            if (header.indexOf("GET /26/on") >= 0) {
              Serial.println("GPIO 26 on");
              output26State = "on";


              writeServos(0, 0);  // Move o servo no canal 0 para a posição 170
              delay(10);
              writeServos(1, 90);  // Move o servo no canal 0 para a posição 170
              delay(10);
              writeServos(2, 180);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(3, 0);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(4, 90);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(5, 180);  // Move o servo no canal 0 para a posição 10
              delay(10);





            } else if (header.indexOf("GET /26/off") >= 0) {
              Serial.println("GPIO 26 off");
              output26State = "off";

              writeServos(0, 90);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(1, 90);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(2, 90);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(3, 90);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(4, 90);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(5, 90);  // Move o servo no canal 0 para a posição 10
              delay(10);
            }
            //_______________________________________________________________________________________________________________

            // BOTÃO 2

            //_______________________________________________________________________________________________________________


            else if (header.indexOf("GET /27/on") >= 0) {
              Serial.println("GPIO 27 on");
              output27State = "on";


              writeServos(6, 180);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(7, 180);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(8, 180);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(9, 180);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(10, 180);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(11, 180);  // Move o servo no canal 0 para a posição 10
              delay(10);

            } else if (header.indexOf("GET /27/off") >= 0) {
              Serial.println("GPIO 27 off");
              output27State = "off";

              writeServos(6, 180);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(7, 180);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(8, 180);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(9, 180);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(10, 180);  // Move o servo no canal 0 para a posição 10
              delay(10);
              writeServos(11, 180);  // Move o servo no canal 0 para a posição 10
              delay(10);
            }


            //_______________________________________________________________________________________________________________

            // BOTÃO 3

            //_______________________________________________________________________________________________________________


            else if (header.indexOf("GET /28/on") >= 0) {
              Serial.println("GPIO 28 on");
              output28State = "on";

              writeServos(6, 60);
              delay(10);
              writeServos(7, 60);
              delay(10);
              writeServos(8, 60);
              delay(10);
              writeServos(9, 60);
              delay(10);
              writeServos(10, 60);
              delay(10);
              writeServos(11, 60);
              delay(10);


            } else if (header.indexOf("GET /28/off") >= 0) {
              Serial.println("GPIO 28 off");
              output28State = "off";

              writeServos(6, 60);
              delay(10);
              writeServos(7, 60);
              delay(10);
              writeServos(8, 60);
              delay(10);
              writeServos(9, 60);
              delay(10);
              writeServos(10, 60);
              delay(10);
              writeServos(11, 60);
              delay(10);



            }

            //_______________________________________________________________________________________________________________

            // BOTÃO 4

            //_______________________________________________________________________________________________________________


            else if (header.indexOf("GET /29/on") >= 0) {
              Serial.println("GPIO 29 on");
              output29State = "on";


              posicaoInicial();




            } else if (header.indexOf("GET /29/off") >= 0) {
              Serial.println("GPIO 29 off");
              output29State = "off";
            }


            //_______________________________________________________________________________________________________________

            // BOTÃO 5

            //_______________________________________________________________________________________________________________


            else if (header.indexOf("GET /30/on") >= 0) {
              Serial.println("GPIO 30 on");
              output30State = "on";


              movimento1();
              delay(10);
              movimento2();
              delay(10);
              movimento3();
              delay(10);

              movimento1();
              delay(10);
              movimento2();
              delay(10);
              movimento3();
              delay(10);
              
              movimento1();
              delay(10);
              movimento2();
              delay(10);
              movimento3();
              delay(10);



            } else if (header.indexOf("GET /30/off") >= 0) {
              Serial.println("GPIO 30 off");
              output30State = "off";

              movimento1();
              delay(10);
              movimento2();
              delay(10);
              movimento3();
              delay(10);

              movimento1();
              delay(10);
              movimento2();
              delay(10);
              movimento3();
              delay(10);
              
              movimento1();
              delay(10);
              movimento2();
              delay(10);
              movimento3();
              delay(10);



            }

            //_______________________________________________________________________________________________________________

            // FIM DOS BOTÕES

            //_______________________________________________________________________________________________________________

            // PÁGINA DA INTERNET

            //_______________________________________________________________________________________________________________


            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");

            // Web Page Heading
            client.println("<body><h1>Spider Bot</h1>");

            // Display current state, and ON/OFF buttons for GPIO 26
            client.println("<p>GPIO 26 - State " + output26State + "</p>");
            // If the output26State is off, it displays the ON button
            if (output26State == "off") {
              client.println("<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            // Display current state, and ON/OFF buttons for GPIO 27
            client.println("<p>GPIO 27 - State " + output27State + "</p>");
            // If the output27State is off, it displays the ON button
            if (output27State == "off") {
              client.println("<p><a href=\"/27/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/27/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            // Display current state, and ON/OFF buttons for GPIO 28
            client.println("<p>GPIO 28 - State " + output28State + "</p>");
            // If the output27State is off, it displays the ON button
            if (output28State == "off") {
              client.println("<p><a href=\"/28/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/28/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            // Display current state, and ON/OFF buttons for GPIO 29
            client.println("<p>GPIO 29 - State " + output29State + "</p>");
            // If the output27State is off, it displays the ON button
            if (output29State == "off") {
              client.println("<p><a href=\"/29/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/29/off\"><button class=\"button button2\">OFF</button></a></p>");
            }


            // Display current state, and ON/OFF buttons for GPIO 30
            client.println("<p>GPIO 30 - State " + output30State + "</p>");
            // If the output27State is off, it displays the ON button
            if (output30State == "off") {
              client.println("<p><a href=\"/30/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/30/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else {  // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}

//___________________________________________________________________________________

// IMPLEMENTO DE FUNÇÕES

//___________________________________________________________________________________


void writeServos(int nServo, int posicao) {
#define SERVOMIN 205  // VALOR PARA UM PULSO MAIOR QUE 1 mS
#define SERVOMAX 409  // VALOR PARA UM PULSO MENOR QUE 2 mS

  int pos = map(posicao, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(nServo, 0, pos);
}

void beginServos() {

#define Frequencia 50  // VALOR DA FREQUENCIA DO SERVO

  pwm.begin();                 // INICIA O OBJETO PWM
  pwm.setPWMFreq(Frequencia);  // DEFINE A FREQUENCIA DE TRABALHO DO SERVO
}
//___________________________________________________________________________________

// FUNÇÕES DE MOVIMENTO

//___________________________________________________________________________________

void posicaoInicial() {

  writeServos(0, 180);  // Move o servo no canal 0 para a posição 170
  delay(10);
  writeServos(1, 90);  // Move o servo no canal 0 para a posição 170
  delay(10);
  writeServos(2, 1);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(3, 90);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(4, 1);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(5, 180);  // Move o servo no canal 0 para a posição 10
  delay(10);
}

void movimento1() {
  writeServos(6, 110);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(10, 110);  // Move o servo no canal 0 para a posição 10
  delay(10);

  writeServos(0, 1);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(4, 180);  // Move o servo no canal 0 para a posição 10
  delay(10);

  writeServos(2, 90);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(5, 90);  // Move o servo no canal 0 para a posição 10
  delay(10);

  writeServos(1, 180);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(3, 0);  // Move o servo no canal 0 para a posição 10
  delay(10);


  writeServos(6, 60);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(10, 60);  // Move o servo no canal 0 para a posição 10
  delay(10);
}

void movimento2() {

  writeServos(7, 110);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(9, 110);  // Move o servo no canal 0 para a posição 10
  delay(10);


  writeServos(1, 1);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(3, 180);  // Move o servo no canal 0 para a posição 10
  delay(10);


  writeServos(0, 90);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(4, 90);  // Move o servo no canal 0 para a posição 10
  delay(10);

  writeServos(2, 180);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(5, 0);  // Move o servo no canal 0 para a posição 10
  delay(10);

  writeServos(7, 60);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(9, 60);  // Move o servo no canal 0 para a posição 10
  delay(10);
}

void movimento3() {

  writeServos(8, 110);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(11, 110);  // Move o servo no canal 0 para a posição 10
  delay(10);

  
  writeServos(1, 90);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(3, 90);  // Move o servo no canal 0 para a posição 10
  delay(10);

  writeServos(0, 180);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(4, 0);  // Move o servo no canal 0 para a posição 10
  delay(10);

  writeServos(2, 0);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(5, 180);  // Move o servo no canal 0 para a posição 10
  delay(10);

  writeServos(8, 60);  // Move o servo no canal 0 para a posição 10
  delay(10);
  writeServos(11, 60);  // Move o servo no canal 0 para a posição 10
  delay(10);



}