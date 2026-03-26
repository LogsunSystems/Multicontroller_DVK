
#define IR_PIN 33

void setup()
{
  pinMode(IR_PIN,INPUT);
  Serial.begin(115200);
}

void loop()
{
  digitalRead(IR_PIN)?Serial.println("Obstacle Detected"):Serial.println("No Obstacle");
  delay(800);
}
