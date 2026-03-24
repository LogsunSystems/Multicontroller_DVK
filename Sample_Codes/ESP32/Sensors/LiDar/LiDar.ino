#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "Adafruit_VL53L0X.h"

// WiFi credentials
const char* ssid = "Logsun";
const char* password = "12345678";

// ThingsBoard MQTT broker details
#define THINGSBOARD_SERVER "demo.thingsboard.io" // Cloud instance
// #define THINGSBOARD_SERVER "YOUR_LOCAL_IP" // For local installation
#define TOKEN "bPvLvZYFY3fWknzLPhB1" // From ThingsBoard device dashboard

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
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
}

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
  Serial.begin(115200);
  setup_wifi();
  client.setServer(THINGSBOARD_SERVER, 1883); // MQTT default port
  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }

  Serial.println("Adafruit VL53L0X test.");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power
  Serial.println(F("VL53L0X API Continuous Ranging example\n\n"));

  // start continuous ranging
  lox.startRangeContinuous();
  delay(1000);
}

void loop() {
  int Distance=0;
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (lox.isRangeComplete()) {
   Distance = lox.readRange();
  }
  // Prepare JSON payload
  StaticJsonDocument<200> doc;
  doc["Distance"] = Distance;
  

  char payload[200];
  serializeJson(doc, payload);

  // Publish to ThingsBoard
  client.publish("v1/devices/me/telemetry", payload);
  Serial.println("Data sent: " + String(payload));

  delay(2500); // Send data every 5 seconds
}


