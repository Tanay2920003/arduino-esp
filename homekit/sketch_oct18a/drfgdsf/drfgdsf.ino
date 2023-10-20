#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <ESPAsyncWebServer.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWiFiManager.h>
#include <HomeSpan.h>

const char* ssid = "TanGo";
const char* password = "Tan292800246080";

AsyncWebServer server(80);
HomeSpan homeSpan;

const int relayPin1 = 13;  // Pin for Relay 1
const int relayPin2 = 12;  // Pin for Relay 2
const int relayPin3 = 14;  // Pin for Relay 3
const int relayPin4 = 27;  // Pin for Relay 4

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  // Connect to Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Initialize HomeSpan
  homeSpan.begin();
  homeSpan.setServiceCount(4); // Number of relays

  // Create your relays
  homeSpan.newAccessory();
  homeSpan.setAccessoryType(HK_LIGHTBULB);
  homeSpan.setName("Relay 1");
  homeSpan.setPin(relayPin1, OUTPUT);
  homeSpan.addOnCharacteristic(0);
  homeSpan.registerHomeKitAccessory();

  homeSpan.newAccessory();
  homeSpan.setAccessoryType(HK_SWITCH);
  homeSpan.setName("AC On/Off");
  homeSpan.setPin(relayPin2, OUTPUT);
  homeSpan.addOnCharacteristic(1);
  homeSpan.registerHomeKitAccessory();

  homeSpan.newAccessory();
  homeSpan.setAccessoryType(HK_FAN);
  homeSpan.setName("Fan");
  homeSpan.setPin(relayPin3, OUTPUT);
  homeSpan.addOnCharacteristic(2);
  homeSpan.registerHomeKitAccessory();

  homeSpan.newAccessory();
  homeSpan.setAccessoryType(HK_FAN);
  homeSpan.setName("Fan");
  homeSpan.setPin(relayPin4, OUTPUT);
  homeSpan.addOnCharacteristic(3);
  homeSpan.registerHomeKitAccessory();

  // Start the server
  server.begin();
}

void loop() {
  // Nothing to do here, just keep looping
}
