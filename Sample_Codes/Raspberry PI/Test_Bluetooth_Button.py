from bluedot import BlueDot
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

#ASSIGN PINS
Blue = 12
Red = 13
Green = 18

count =0
#make GPIO as OUTPUT
GPIO.setup(Red, GPIO.OUT)
GPIO.setup(Green, GPIO.OUT)
GPIO.setup(Blue, GPIO.OUT)
#GPIO as LOW
GPIO.output(Red,GPIO.LOW)
GPIO.output(Green,GPIO.LOW)
GPIO.output(Blue,GPIO.LOW)
bd = BlueDot()

while True:
    bd.wait_for_press() #button will touch
    count = count +1
    if(count ==1):
        
        print("Red ON")
        GPIO.output(Red,GPIO.HIGH)  #RED LED ON
        bd.wait_for_release()
        print("Red OFF")
        GPIO.output(Red,GPIO.LOW)
    if (count == 2):
        print("Green ON")
        GPIO.output(Green,GPIO.HIGH) #GREEN LED ON
        bd.wait_for_release()
        print("Green OFF")
        GPIO.output(Green,GPIO.LOW)
    if (count ==3):
        print("Blue ON")
        GPIO.output(Blue,GPIO.HIGH)   #BLUE LED ON
        bd.wait_for_release()
        print("Blue OFF")
        GPIO.output(Blue,GPIO.LOW)
        count =0
    
    
