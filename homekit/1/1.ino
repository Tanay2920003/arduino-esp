#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "TanGo";
const char* password = "Tan292800246080";

const int relay1Pin = 13;
const int relay2Pin = 12;
const int relay3Pin = 14;
const int relay4Pin = 15;

bool relay1State = false;
bool relay2State = false;
bool relay3State = false;
bool relay4State = false;

AsyncWebServer server(80);

void setup() {
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(relay3Pin, OUTPUT);
  pinMode(relay4Pin, OUTPUT);

  digitalWrite(relay1Pin, relay1State);
  digitalWrite(relay2Pin, relay2State);
  digitalWrite(relay3Pin, relay3State);
  digitalWrite(relay4Pin, relay4State);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request){
    String html = "<html><body>";
    html += "<h1>ESP32 Relay Control</h1>";
    html += "<p>Relay 1: <a href=\"/toggleRelay1\">Toggle</a></p>";
    html += "<p>Relay 2: <a href=\"/toggleRelay2\">Toggle</a></p>";
    html += "<p>Relay 3: <a href=\"/toggleRelay3\">Toggle</a></p>";
    html += "<p>Relay 4: <a href=\"/toggleRelay4\">Toggle</a></p>";
    html += "</body></html>";
    request->send(200, "text/html", html);
  });

  server.on("/toggleRelay1", HTTP_GET, [](AsyncWebServerRequest* request){
    relay1State = !relay1State;
    digitalWrite(relay1Pin, relay1State);
    request->send(200, "text/plain", relay1State ? "Relay 1 ON" : "Relay 1 OFF");
  });

  server.on("/toggleRelay2", HTTP_GET, [](AsyncWebServerRequest* request){
    relay2State = !relay2State;
    digitalWrite(relay2Pin, relay2State);
    request->send(200, "text/plain", relay2State ? "Relay 2 ON" : "Relay 2 OFF");
  });

  server.on("/toggleRelay3", HTTP_GET, [](AsyncWebServerRequest* request){
    relay3State = !relay3State;
    digitalWrite(relay3Pin, relay3State);
    request->send(200, "text/plain", relay3State ? "Relay 3 ON" : "Relay 3 OFF");
  });

  server.on("/toggleRelay4", HTTP_GET, [](AsyncWebServerRequest* request){
    relay4State = !relay4State;
    digitalWrite(relay4Pin, relay4State);
    request->send(200, "text/plain", relay4State ? "Relay 4 ON" : "Relay 4 OFF");
  });

  server.begin();
}

void loop() {
}
