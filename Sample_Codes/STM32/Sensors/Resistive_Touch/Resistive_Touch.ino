#define TOUCH_PIN  A0

void setup()
{
  Serial1.begin(9600);
  pinMode(TOUCH_PIN,INPUT);
  delay(100);
}

void loop()
{
  int RT = digitalRead(TOUCH_PIN);
  String payload = "{\"TOUCH-SW\":" + String(RT) + "}";

  //Serial.println(payload);
  Serial1.print(payload);

  delay(5000);

}