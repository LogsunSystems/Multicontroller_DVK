import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

Relay_1 = 14
Relay_2 = 15

GPIO.setup(Relay_1, GPIO.OUT)
GPIO.output(Relay_1, GPIO.LOW)

GPIO.setup(Relay_2, GPIO.OUT)
GPIO.output(Relay_2, GPIO.LOW)

while(True):
    GPIO.output(Relay_1, GPIO.HIGH)
    GPIO.output(Relay_2, GPIO.LOW)
    time.sleep(2)
    GPIO.output(Relay_1, GPIO.LOW)
    GPIO.output(Relay_2, GPIO.LOW)
    time.sleep(2)

