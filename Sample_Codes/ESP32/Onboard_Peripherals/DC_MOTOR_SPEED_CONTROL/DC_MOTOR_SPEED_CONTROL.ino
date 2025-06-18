int speedPin = 17;
int dir1 = 19;
int dir2 = 23;
int Switch_1 = 36;
int Switch_2 = 39;
int Switch_3 = 34;
int Switch_4 = 35;
int Switch_5 = 32;

int SW1;
int SW2;
int SW3;
int SW4;
int SW5;

int mSpeed = 0;
int dt = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(Switch_1, INPUT);
  pinMode(Switch_2, INPUT);
  pinMode(Switch_3, INPUT);
  pinMode(Switch_4, INPUT);
  pinMode(Switch_5, INPUT);
  digitalWrite(Switch_1, HIGH);
  digitalWrite(Switch_2, HIGH);
  digitalWrite(Switch_3, HIGH);
  digitalWrite(Switch_4, HIGH);
  digitalWrite(Switch_5, HIGH);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  SW1 = digitalRead(Switch_1);
  SW2 = digitalRead(Switch_2);
  SW3 = digitalRead(Switch_3);
  SW4 = digitalRead(Switch_4);
  SW5 = digitalRead(Switch_5);
  Serial.println(SW1);
  Serial.println(SW2);
  Serial.println(SW3);
  Serial.println(SW4);
  Serial.println(SW5);

  Serial.print("Motor Speed ");
  Serial.println(mSpeed);

  if (SW4 == 0) {
    Serial.println("Decrement");
    mSpeed = mSpeed - 10;
    delay(dt);
  }
  if (SW3 == 0) {
    Serial.println("Increment");
    mSpeed = mSpeed + 10;
    delay(dt);
  }
  if (SW5 == 0)
  {
    mSpeed = 0;
    Serial.println("stop");
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
    analogWrite(speedPin, mSpeed);

  }
  if (SW1 == 0)
  {
    mSpeed = 100;
    Serial.println("start");
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin, mSpeed);
  }
  if (SW2 == 0)
  {
    mSpeed = -100;
    Serial.println("reverse");
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    analogWrite(speedPin, mSpeed);
  }
  if (mSpeed > 255) {
    mSpeed = 255;
  }
  if (mSpeed < -255) {
    mSpeed = -255;
  }
  if (mSpeed == 10) {
    mSpeed = 100;
  }
  if (mSpeed == -10) {
    mSpeed = -100;
  }
  if (mSpeed == 90 || mSpeed == 95) {
    mSpeed = 0;
  }
  if (mSpeed == -90 || mSpeed == -95) {
    mSpeed = 0;
  }
  if (mSpeed == 0) {
    analogWrite(speedPin, 0);
  }
  if (mSpeed > 0) {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    analogWrite(speedPin, mSpeed);
  }
  if (mSpeed < 0) {
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    analogWrite(speedPin, abs(mSpeed));
  }
}
