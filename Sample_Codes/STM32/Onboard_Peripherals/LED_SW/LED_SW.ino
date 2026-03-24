#define LED1  PB4
#define LED2  PB5
#define LED3  PB3
#define LED4  PA15
#define LED5  PA4
#define LED6  PA5
#define LED7  PA6
#define LED8  PA7

#define SW1   PA8
#define SW3   PA1
#define SW4   PA3
#define SW2   PA11
#define SW5   PA12
#define SW6   PB7
#define SW7   PB13
#define SW8   PB14


void setup()
{
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(LED6,OUTPUT);
  pinMode(LED7,OUTPUT);
  pinMode(LED8,OUTPUT);

  pinMode(SW1,INPUT);
  pinMode(SW2,INPUT);
  pinMode(SW3,INPUT);
  pinMode(SW4,INPUT);
  pinMode(SW5,INPUT);
  pinMode(SW6,INPUT);
  pinMode(SW7,INPUT);
  pinMode(SW8,INPUT);
}

void loop()
{
  digitalRead(SW1)?digitalWrite(LED1,HIGH):digitalWrite(LED1,LOW);
  digitalRead(SW2)?digitalWrite(LED2,HIGH):digitalWrite(LED2,LOW);
  digitalRead(SW3)?digitalWrite(LED3,HIGH):digitalWrite(LED3,LOW);
  digitalRead(SW4)?digitalWrite(LED4,HIGH):digitalWrite(LED4,LOW);
  digitalRead(SW5)?digitalWrite(LED5,HIGH):digitalWrite(LED5,LOW);
  digitalRead(SW6)?digitalWrite(LED6,HIGH):digitalWrite(LED6,LOW);
  digitalRead(SW7)?digitalWrite(LED7,HIGH):digitalWrite(LED7,LOW);
  digitalRead(SW8)?digitalWrite(LED8,HIGH):digitalWrite(LED8,LOW);

}