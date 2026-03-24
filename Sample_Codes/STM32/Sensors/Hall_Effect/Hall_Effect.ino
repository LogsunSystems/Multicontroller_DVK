#define HALL_PIN  A0

void setup()
{
  Serial1.begin(9600);
  pinMode(HALL_PIN,INPUT);
  delay(100);
}

void loop()
{
  int hall = digitalRead(HALL_PIN);
  String payload = "{\"HALL\":" + String(hall) + "}";

  //Serial.println(payload);
  Serial1.print(payload);

  delay(5000);

}