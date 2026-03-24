#include "DHT.h"
#include <WiFiEspClient.h>
#include <WiFiEsp.h>
#include <WiFiEspUdp.h>
#include "SoftwareSerial.h"
#include <ThingsBoard.h>

#define WIFI_AP "ACER"
#define WIFI_PASSWORD "12345678"

#define TOKEN "bdThfGxgIYh7TmSuLrM8"

// DHT
#define tiltSensorPin A0

char thingsboardServer[] = "demo.thingsboard.io";

// Initialize the Ethernet client object
WiFiEspClient espClient;

// Initialize DHT sensor.


ThingsBoard tb(espClient);

SoftwareSerial soft(2, 3);  // RX, TX
int tiltVal;
int status = WL_IDLE_STATUS;
unsigned long lastSend;

void setup() {
  // initialize serial for debugging
  Serial.begin(9600);
  
  InitWiFi();
  lastSend = 0;
  pinMode(tiltSensorPin, INPUT);
}

void loop() {
  status = WiFi.status();
  if (status != WL_CONNECTED) {
    while (status != WL_CONNECTED) {
      Serial.print("Attempting to connect to WPA SSID: ");
      Serial.println(WIFI_AP);
      // Connect to WPA/WPA2 network
      status = WiFi.begin(WIFI_AP, WIFI_PASSWORD);
      delay(500);
    }
    Serial.println("Connected to AP");
  }

  if (!tb.connected()) {
    reconnect();
  }

  if (millis() - lastSend > 1000) {  // Update and send only after 1 seconds
    getAndSendLdrData();
    lastSend = millis();
  }

  tb.loop();
}

void getAndSendLdrData() {
  Serial.println("Collecting Hall Effect sensor data.");
     tiltVal = digitalRead(tiltSensorPin);
  // if (ldrStatus <= 200) {
  //   Serial.print("Darkness over here,turn on the LED :");
  //   Serial.println(ldrStatus);
  // } else {

  //   Serial.print("There is sufficient light , turn off the LED : ");
  //   Serial.println(ldrStatus);
  // }
  Serial.println("Sending data to ThingsBoard:");
  Serial.print("Tilt Switch: ");
  Serial.print(tiltVal);

  tb.sendTelemetryInt("TiltSwitch", tiltVal);
  //tb.sendTelemetryFloat("humidity", humidity);
}

void InitWiFi() {
  // initialize serial for ESP module
  soft.begin(9600);
  // initialize ESP module
  WiFi.init(&soft);
  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true)
      ;
  }

  Serial.println("Connecting to AP ...");
  // attempt to connect to WiFi network
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(WIFI_AP);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(WIFI_AP, WIFI_PASSWORD);
    delay(500);
  }
  Serial.println("Connected to AP");
}

void reconnect() {
  // Loop until we're reconnected
  while (!tb.connected()) {
    Serial.print("Connecting to ThingsBoard node ...");
    // Attempt to connect (clientId, username, password)
    if (tb.connect(thingsboardServer, TOKEN)) {
      Serial.println("[DONE]");
    } else {
      Serial.print("[FAILED]");
      Serial.println(" : retrying in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}