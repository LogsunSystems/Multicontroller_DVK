
#define LDR_PIN PA0

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  Serial1.begin(9600); // ESP8266 default baud rate
}

void loop() {
  // put your main code here, to run repeatedly:
  int Light = analogRead(LDR_PIN);
  // Tiny JSON payload (to save memory)
  String payload = "{\"LDR\":" + String(Light)  + "}";

  //Serial.println(payload);
  Serial1.print(payload);

  delay(5000);
}
