###########################################################
#Stepper Motor interface with Raspberry pi-3
#Compony Name- Logsun Systems
###########################################################
#Connections-
#EN1-GPIO-19 EN2-GPIO-20
#IP1-GPIO-21 P2-GPIO-22
#IP3-GPIO-23 IP4-GPIO-24
##########################################################
import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

#assign GPIO pins for motor
EN1 = 21
EN2 = 20
IP1 = 19
IP2 = 12
IP3 = 7
IP4 = 8

motor_channel = (IP1,IP2,IP3,IP4)

#for defining more than 1 GPIO channel as input/output use
GPIO.setup(motor_channel, GPIO.OUT)
GPIO.setup(EN1, GPIO.OUT)
GPIO.setup(EN2, GPIO.OUT)

#Get input from user
print('Press: a or c for motor direction then Press:Ctrl+c to Stop or Change Direction\r\n')
motor_direction = input('Select Motor Direction a=Anticlockwise, c=Clockwise: ')

#infinite Loop:
while(True):
    GPIO.output(EN1, GPIO.HIGH)
    GPIO.output(EN2, GPIO.HIGH)
    try:
        if(motor_direction == 'a'):
            GPIO.output(motor_channel, (GPIO.HIGH,GPIO.LOW,GPIO.LOW,GPIO.HIGH))
            sleep(0.01)
            GPIO.output(motor_channel, (GPIO.HIGH,GPIO.HIGH,GPIO.LOW,GPIO.LOW))
            sleep(0.01)
            GPIO.output(motor_channel, (GPIO.LOW,GPIO.HIGH,GPIO.HIGH,GPIO.LOW))
            sleep(0.01)
            GPIO.output(motor_channel, (GPIO.LOW,GPIO.LOW,GPIO.HIGH,GPIO.HIGH))
            sleep(0.01)

        elif(motor_direction == 'c'):
            GPIO.output(motor_channel, (GPIO.HIGH,GPIO.LOW,GPIO.LOW,GPIO.HIGH))
            sleep(0.01)
            GPIO.output(motor_channel, (GPIO.LOW,GPIO.LOW,GPIO.HIGH,GPIO.HIGH))
            sleep(0.01)
            GPIO.output(motor_channel, (GPIO.LOW,GPIO.HIGH,GPIO.HIGH,GPIO.LOW))
            sleep(0.01)
            GPIO.output(motor_channel, (GPIO.HIGH,GPIO.HIGH,GPIO.LOW,GPIO.LOW))
            sleep(0.01)

    #press ctrl+c for keyboard interrupt
    except KeyboardInterrupt:
        #query for setting motor direction or exit
        motor_direction = input('Select Motor Direction a=Anticlockwise, c=Clockwise or e=Exit: ')
        #check for exit
        if(motor_direction == 'e'):
            GPIO.output(EN1, GPIO.LOW)
            GPIO.output(EN2, GPIO.LOW)
            GPIO.output(motor_channel, (GPIO.LOW,GPIO.LOW,GPIO.LOW,GPIO.LOW))
            print('Motor Stopped\r\nExiting Program...\r\n')
            GPIO.cleanup()
            exit(0)
