
#define EN1 12
#define EN2 13
#define IN1 14
#define IN2 25
#define IN3 26
#define IN4 27

#define START 4
#define STOP  32
#define REV   0
#define INC   2
#define DEC   15

#define PERIOD_MAX 100U
#define PERIOD_MIN 30U

#define DEBOUNCE 350U

bool dir = false, Run = false;
int period = 60;

void setup() {
  pinMode(START, INPUT);
  pinMode(STOP, INPUT);
  pinMode(REV, INPUT);
  pinMode(INC, INPUT);
  pinMode(DEC, INPUT);

  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(EN1, LOW);
  digitalWrite(EN2, LOW);
}

void loop() {
  if (!digitalRead(START)) {
    Run = true;
    dir = true;
    digitalWrite(EN1,HIGH);
    digitalWrite(EN2,HIGH);
    delay(DEBOUNCE);
  }

  if (!digitalRead(STOP)) {
    Run = false;
    digitalWrite(EN1, LOW);
    digitalWrite(EN2, LOW);
    delay(DEBOUNCE);
  }

  if ((!digitalRead(REV)) && Run) {
    dir = !dir;
    delay(DEBOUNCE);
  }

  if (!digitalRead(INC)) {
    if (period > PERIOD_MIN) {
      period -= 10;
    } else {
      period = PERIOD_MIN;
    }
    delay(DEBOUNCE);
  }

  if (!digitalRead(DEC)) {
    if (period < PERIOD_MAX) {
      period += 10;
    } else {
      period = PERIOD_MAX;
    }
    delay(DEBOUNCE);
  }


  if (Run) {
    if (dir) {
      //Clockwise Direction
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      delay(period);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(period);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(period);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(period);
    } else {
      //Anticlockwise Direction
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(period);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(period);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(period);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      delay(period);
    }
  }
  else
  {
    digitalWrite(EN1,LOW);
    digitalWrite(EN2,LOW);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);

  }

  
}