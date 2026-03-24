import RPi.GPIO as GPIO
import time
GPIO.setwarnings(False)


LED_1 = 4
LED_2 = 17
LED_3 = 27
LED_4 = 22
LED_5 = 23
LED_6 = 24
LED_7 = 25
LED_8 = 18

SW_1 = 5
SW_2 = 6
SW_3 = 13
SW_4 = 19
SW_5 = 26
SW_6 = 16
SW_7 = 20
SW_8 = 21


GPIO.setmode(GPIO.BCM)       # Use BCM GPIO numbers
GPIO.setup(LED_1, GPIO.OUT) 
GPIO.setup(LED_2, GPIO.OUT) 
GPIO.setup(LED_3, GPIO.OUT) 
GPIO.setup(LED_4, GPIO.OUT) 
GPIO.setup(LED_5, GPIO.OUT)
GPIO.setup(LED_6, GPIO.OUT) 
GPIO.setup(LED_7, GPIO.OUT)
GPIO.setup(LED_8, GPIO.OUT)

GPIO.setup(SW_1, GPIO.IN) 
GPIO.setup(SW_2, GPIO.IN) 
GPIO.setup(SW_3, GPIO.IN) 
GPIO.setup(SW_4, GPIO.IN) 
GPIO.setup(SW_5, GPIO.IN)
GPIO.setup(SW_6, GPIO.IN) 
GPIO.setup(SW_7, GPIO.IN)
GPIO.setup(SW_8, GPIO.IN)


while True:
    if (GPIO.input(SW_1)):
        GPIO.output(LED_1,True)
    else:
        GPIO.output(LED_1,False)
    if (GPIO.input(SW_2)):
        GPIO.output(LED_2,True)
    else:
        GPIO.output(LED_2,False)
    if (GPIO.input(SW_3)):
        GPIO.output(LED_3,True)
    else:
        GPIO.output(LED_3,False)
    if (GPIO.input(SW_4)):
        GPIO.output(LED_4,True)
    else:
        GPIO.output(LED_4,False)
    if (GPIO.input(SW_5)):
        GPIO.output(LED_5,True)
    else:
        GPIO.output(LED_5,False)
    if (GPIO.input(SW_6)):
        GPIO.output(LED_6,True)
    else:
        GPIO.output(LED_6,False)
    if (GPIO.input(SW_7)):
        GPIO.output(LED_7,True)
    else:
        GPIO.output(LED_7,False)
    if (GPIO.input(SW_8)):
        GPIO.output(LED_8,True)
    else:
        GPIO.output(LED_8,False)

