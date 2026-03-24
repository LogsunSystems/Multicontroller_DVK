#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>


// WiFi credentials
const char* ssid = "Logsun";
const char* password = "12345678";

// ThingsBoard MQTT broker details
#define THINGSBOARD_SERVER "demo.thingsboard.io" // Cloud instance
// #define THINGSBOARD_SERVER "YOUR_LOCAL_IP" // For local installation
#define TOKEN "bPvLvZYFY3fWknzLPhB1" // From ThingsBoard device dashboard


WiFiClient espClient;
PubSubClient client(espClient);
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);


void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    
    if (client.connect("ESP32Client", TOKEN, NULL)) {
      Serial.println("Connected to ThingsBoard!");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Retrying in 5 seconds...");
      delay(5000);
    }
  }
}


void setup() {
  // initialize serial for debugging
  Serial.begin(9600);

  delay(10);
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
   client.setServer(THINGSBOARD_SERVER, 1883); // MQTT default port

  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
  
}

void loop() {
  uint16_t R=0,G=0,B=0,C=0;

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  tcs.getRawData(&R, &G, &B, &C);

  StaticJsonDocument<200> doc;
  doc["Red"] = R;
  doc["Green"] = G;
  doc["Blue"] = B;
  doc["Black"] = C;

  char payload[200];
  serializeJson(doc, payload);

  // Publish to ThingsBoard
  client.publish("v1/devices/me/telemetry", payload);
  Serial.println("Data sent: " + String(payload));    
  delay(1200);
}

