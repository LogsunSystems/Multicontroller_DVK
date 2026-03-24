#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>

/****** WiFi Connection Details *******/
const char* ssid = "WIFINAME";
const char* password = "PASSWORD";

/******* MQTT Broker Connection Details *******/
// ThingsBoard MQTT broker details
#define THINGSBOARD_SERVER "demo.thingsboard.io"  // Cloud instance
// #define THINGSBOARD_SERVER "YOUR_LOCAL_IP" // For local installation
#define TOKEN "bPvLvZYFY3fWknzLPhB1"  // From ThingsBoard device dashboard

const int mqtt_port = 1883;
bool Flag_SEND= false;

//char Buff[256] = { '\0' };
String Data = "";

/**** Secure WiFi Connectivity Initialisation *****/
WiFiClient espClient;


/**** MQTT Client Initialisation Using WiFi Connection *****/
PubSubClient client(espClient);

/************* Connect to WiFi ***********/
void setup_wifi() {
  delay(10);
  //Serial.print("\nConnecting to ");
  //Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.print(".");
  }
  randomSeed(micros());
  //Serial.println("\nWiFi connected\nIP address: ");
  //Serial.println(WiFi.localIP());
}

/************* Connect to MQTT Broker ***********/
void reconnect() {
  while (!client.connected()) {
    //Serial.print("Attempting MQTT connection...");

    if (client.connect("ESP8266Client", TOKEN, NULL)) {
      //Serial.println("Connected to ThingsBoard!");
    } else {
      //Serial.print("Failed, rc=");
      //Serial.print(client.state());
      //Serial.println(" Retrying in 5 seconds...");
      delay(5000);
    }
  }
}


bool checkJSON(String json) {
  if (json.indexOf("}") == -1) {
    return false;
  } else {
    return true;
  }
}




/**** Method for Publishing MQTT Messages **********/
void publishMessage(const char* topic, String payload, boolean retained) {
  if (client.publish(topic, payload.c_str(), true))
    Serial.println("Message publised [" + String(topic) + "]: " + payload);
  digitalWrite(LED_BUILTIN, LOW);
  delay(80);
  digitalWrite(LED_BUILTIN, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  while (!Serial) delay(1);
  setup_wifi();
  //espClient.setInsecure();
  client.setServer(THINGSBOARD_SERVER, 1883);
}

void loop() {
  if (!client.connected()) reconnect();  // check if client is connected
  client.loop();

  if (Serial.available()) {
    //int cnt = 0;
    //memset(Buff, '\0', 256);

    while (Serial.available() > 0) {
      //Buff[cnt] = Serial.read();
      Data = Serial.readStringUntil('\r');
      //cnt++;
    }
    Serial.print("[Data Received]"); 
    //Data = String(Buff);
    Serial.println(Data);
    Flag_SEND = true;
  }
  

  if(Flag_SEND && checkJSON(Data))
  {
    //client.publish("v1/devices/me/telemetry", payload.c_str());
    Serial.println(Data);
    publishMessage("v1/devices/me/telemetry", Data, true);
    Flag_SEND = false;
    Data.clear();
    Serial.flush();
  }
  
  
  
}


// {"Data":"22365"}