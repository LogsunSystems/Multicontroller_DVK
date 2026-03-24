#define LED1  GPIO_NUM_4
#define LED2  GPIO_NUM_17
#define LED3  GPIO_NUM_16
#define LED4  GPIO_NUM_5
#define LED5  GPIO_NUM_18
#define LED6  GPIO_NUM_19
#define LED7  GPIO_NUM_23
#define LED8  GPIO_NUM_15

#define SW1   GPIO_NUM_12
#define SW2   GPIO_NUM_13
#define SW3   GPIO_NUM_14
#define SW4   GPIO_NUM_25
#define SW5   GPIO_NUM_26
#define SW6   GPIO_NUM_27
#define SW7   GPIO_NUM_32
#define SW8   GPIO_NUM_33


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