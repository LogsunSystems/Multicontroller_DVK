
#define RED     GPIO_NUM_2
#define GREEN   GPIO_NUM_21
#define BLUE    GPIO_NUM_0

#define POT_1   GPIO_NUM_25
#define POT_2   GPIO_NUM_33
#define POT_3   GPIO_NUM_32

uint16_t red, green, blue, raw_1, raw_2, raw_3;

void setup()
{
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);

  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);

  Serial.begin(115200);


}

void loop()
{
  raw_1 = analogRead(POT_1);
  raw_2 = analogRead(POT_2);
  raw_3 = analogRead(POT_3);

 

  red = map(raw_1,0,4095,0,255);
  blue = map(raw_2,0,4095,0,255);
  green = map(raw_3, 0,4095,0,255);

  analogWrite(RED,red);
  analogWrite(BLUE,blue);
  analogWrite(GREEN,green);
  
  delay(30);
}