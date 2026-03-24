#define TILT_PIN  A0

void setup()
{
  Serial1.begin(9600);
  pinMode(TILT_PIN,INPUT);
  delay(100);
}

void loop()
{
  int SW = digitalRead(TILT_PIN);
  String payload = "{\"Tilt-SW\":" + String(SW) + "}";

  //Serial.println(payload);
  Serial1.print(payload);

  delay(5000);

}