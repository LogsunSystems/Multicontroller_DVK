//INTERFACE SERVO WITH STM32
//CIRCUIT DIGEST
#include<Servo.h>                                                          //including servo library
int servoPin = PA6;                                //declare and initialize pin for servo output PWM 

Servo servo;                                            // creating variable servo with datatype Servo
void setup()                            
{ 
                                                                //clears lcd display
  servo.attach(servoPin);   //it connects pin PA0 with motor as control feedback by providing pulses
}
void loop()
{
  //Rotate motor from 0 to 170 degrees
 for (int i=0;i<170;i+10)
 {
    servo.write(i);
    delay(100); 
 }

delay(2000);

//Rotate motor from 170 to 0 degrees
 for (int i=170;i>=0;i-10)
 {
    servo.write(i);
    delay(100); 
 }

                                                             //puts value at angle
                                                                   //delay in time
}