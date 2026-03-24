
#define CO_PIN PA0  //Define Sensor Pin

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  Serial1.begin(9600); // ESP8266 default baud rate
}

void loop() {
  // put your main code here, to run repeatedly:
  int Gas = analogRead(CO_PIN); //Read Sensor Data
  // Tiny JSON payload (to save memory)
  String payload = "{\"CO\":" + String(Gas)  + "}";

  //Serial.println(payload);
  Serial1.print(payload); //Send to Cloud

  delay(5000);
}
