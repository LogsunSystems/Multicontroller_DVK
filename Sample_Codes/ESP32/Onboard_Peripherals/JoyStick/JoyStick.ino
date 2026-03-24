#define UP    0
#define DOWN  4
#define MID   2
#define LEFT  32
#define RIGHT 15


void setup() {
  // put your setup code here, to run once:
  pinMode(UP,INPUT);
  pinMode(DOWN,INPUT);
  pinMode(MID,INPUT);
  pinMode(LEFT,INPUT);
  pinMode(RIGHT,INPUT);

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalRead(UP)?Serial.print("\0"):Serial.println("UP");
  digitalRead(DOWN)?Serial.print("\0"):Serial.println("DOWN");
  digitalRead(MID)?Serial.print("\0"):Serial.println("MID");
  digitalRead(LEFT)?Serial.print("\0"):Serial.println("LEFT");
  digitalRead(RIGHT)?Serial.print("\0"):Serial.println("RIGHT");
  delay(100);
}
