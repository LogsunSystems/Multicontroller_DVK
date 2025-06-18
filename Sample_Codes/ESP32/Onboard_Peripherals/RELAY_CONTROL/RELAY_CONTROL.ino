int relay_1 = 1;
int relay_2 = 15;
int buzzer = 4;
//int redPin = 15;
//int greenPin = 14;
//int bluePin = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
//  pinMode(redPin, OUTPUT);
//  pinMode(greenPin, OUTPUT);
//  pinMode(bluePin, OUTPUT);
//  digitalWrite(redPin, LOW);
//  digitalWrite(greenPin, LOW);
//  digitalWrite(bluePin, LOW);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relay_1, HIGH);
  digitalWrite(relay_2, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(relay_1, LOW);
  digitalWrite(relay_2, LOW);
  digitalWrite(buzzer, LOW);
  delay(1000);
}
