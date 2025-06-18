#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int stepsPerRevolution_0 = 0;
// ULN2003 Motor Driver Pins
#define IN1 19
#define IN2 23
#define IN3 18
#define IN4 5
int mSpeed = 0;
int dt = 500;
int Switch_1 = 36;
int Switch_2 = 39;
int Switch_3 = 34;
int Switch_4 = 35;
int Switch_5 = 32;

int dir1;
int dir2;

int SW1;
int SW2;
int SW3;
int SW4;
int SW5;
// initialize the stepper library
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  // set the speed at 5 rpm

  // initialize the serial port
  Serial.begin(115200);
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
}

void loop() {
  // step one revolution in one direction:
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

  Serial.print("dir1 = ");
  Serial.println(dir1);
  Serial.print("dir2 = ");
  Serial.println(dir2);

  if (SW5 == 0)
  {
    dir1 = 0;
    dir2 = 0;
    mSpeed = 0;
    Stop();
  }
  if (SW1 == 0)
  {
    dir2 = 0;
    dir1 = 1;
  }
  if (dir1 == 1)
  {
    myStepper.setSpeed(3);
    Serial.println("clockwise");
    myStepper.step(stepsPerRevolution / 10);
  }
  if (SW4 == 0)
  {
    dir1 = 0;
    dir2 = 1;
  }
  if (dir2 == 1)
  {
    myStepper.setSpeed(3);
    Serial.println("counterclockwise");
    myStepper.step(-stepsPerRevolution / 10);
  }
  if (SW3 == 0) {
    dir1 = 0;
    dir2 = 0;
    Serial.println("Decrement");
    mSpeed = mSpeed - 3;
    delay(dt);
  }
  if (SW2 == 0) {
    dir1 = 0;
    dir2 = 0;
    Serial.println("Increment");
    mSpeed = mSpeed + 3;
    delay(dt);
  }
  Serial.print("Motor Speed ");
  Serial.println(mSpeed);

  if (mSpeed > 18) {
    dir1 = 0;
    dir2 = 0;
    mSpeed = 18;
  }
  if (mSpeed < -18) {
    dir1 = 0;
    dir2 = 0;
    mSpeed = -18;
  }
  //  if (mSpeed == 10) {
  //    mSpeed = 50;
  //  }
  //  if (mSpeed == -10) {
  //    mSpeed = -50;
  //  }
  //  if (mSpeed == 40 || mSpeed == 45) {
  //    mSpeed = 0;
  //  }
  //  if (mSpeed == -40 || mSpeed == -45) {
  //    mSpeed = 0;
  //  }
  //  if (mSpeed == 0) {
  //    myStepper.setSpeed(mSpeed);
  //  }
  if (mSpeed > 0)
  {
    dir1 = 0;
    dir2 = 0;
    myStepper.setSpeed(mSpeed);
    myStepper.step(stepsPerRevolution / 10);
  }
  if (mSpeed == -3)
  {
    dir1 = 0;
    dir2 = 0;
    myStepper.setSpeed(3);
    myStepper.step(-stepsPerRevolution / 10);
  }
  if (mSpeed == -6)
  {
    dir1 = 0;
    dir2 = 0;
    myStepper.setSpeed(6);
    myStepper.step(-stepsPerRevolution / 10);
  }
  if (mSpeed == -9)
  {
    dir1 = 0;
    dir2 = 0;
    myStepper.setSpeed(9);
    myStepper.step(-stepsPerRevolution / 10);
  }
  if (mSpeed == -12)
  {
    dir1 = 0;
    dir2 = 0;
    myStepper.setSpeed(12);
    myStepper.step(-stepsPerRevolution / 10);
  }
  if (mSpeed == -15)
  {
    dir1 = 0;
    dir2 = 0;
    myStepper.setSpeed(15);
    myStepper.step(-stepsPerRevolution / 10);
  }
  if (mSpeed == -18)
  {
    dir1 = 0;
    dir2 = 0;
    myStepper.setSpeed(18);
    myStepper.step(-stepsPerRevolution / 10);
  }
}

void Stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
