#include <ESP32Servo.h> 
 
#define SERVO_PIN 21
 
Servo servoMotor;  
 
void setup()
{
    servoMotor.attach(SERVO_PIN);
}
 
void loop()
{
     servoMotor.write(0); // Rotate Servo to 0 Degrees
     delay(500); // Delay to allow Servo time to Move
     servoMotor.write(90); // Rotate Servo to 90 Degrees
     delay(500); // Delay to allow Servo time to Move
     servoMotor.write(180); // Rotate Servo to 180 Degrees
     delay(500); // Delay to allow Servo time to Move
     servoMotor.write(45); // Rotate Servo to 90 Degrees
     delay(500); // Delay to allow Servo time to Move
}
