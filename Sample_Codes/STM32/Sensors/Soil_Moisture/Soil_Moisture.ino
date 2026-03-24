
#define SOIL_PIN PA0

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  Serial1.begin(9600); // ESP8266 default baud rate
}

void loop() {
  // put your main code here, to run repeatedly:
  int SM = analogRead(SOIL_PIN);// Read the Sensor Value
  // Tiny JSON payload (to save memory)
  String payload = "{\"SOIL_MOISTURE\":" + String(SM)  + "}";

  //Serial.println(payload);
  Serial1.print(payload);

  delay(5000);
}
