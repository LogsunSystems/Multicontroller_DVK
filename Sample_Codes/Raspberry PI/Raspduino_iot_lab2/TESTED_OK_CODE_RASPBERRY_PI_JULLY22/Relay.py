import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

Relay = 5

GPIO.setup(Relay, GPIO.OUT)
GPIO.output(Relay, GPIO.LOW)

while(True):
    GPIO.output(Relay, GPIO.HIGH)
    time.sleep(2)
    GPIO.output(Relay, GPIO.LOW)
    time.sleep(2)

