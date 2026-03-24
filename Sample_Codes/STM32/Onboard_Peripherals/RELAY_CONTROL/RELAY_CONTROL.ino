int relay_1 = PA0;
int relay_2 = PA1;
int buzzer = PA3;
int redPin = PA4;
int greenPin = PA5;
int bluePin = PA2;
void setup() {
  // put your setup code here, to run once:
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(buzzer, LOW);
  delay(1000);

  digitalWrite(buzzer, HIGH);
  delay(1000);

  digitalWrite(relay_1, HIGH);
  delay(1000);
  digitalWrite(relay_1, LOW);
  delay(1000);
  digitalWrite(relay_2, HIGH);
  delay(1000);
  digitalWrite(relay_2, LOW);
  delay(1000);

  digitalWrite(redPin, HIGH);
  delay(1000);
  digitalWrite(redPin, LOW);
  delay(1000);

  digitalWrite(greenPin, HIGH);
  delay(1000);
  digitalWrite(greenPin, LOW);
  delay(1000);

  digitalWrite(bluePin, HIGH);
  delay(1000);
  digitalWrite(bluePin, LOW);
  delay(1000);
  //   digitalWrite(relay_1, HIGH);
  // digitalWrite(relay_2, HIGH);
}
