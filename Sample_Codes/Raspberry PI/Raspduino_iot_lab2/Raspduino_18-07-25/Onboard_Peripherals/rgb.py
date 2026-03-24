import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)

GPIO.setup(12, GPIO.OUT)
GPIO.setup(13, GPIO.OUT)
GPIO.setup(18, GPIO.OUT)

while(True):
    GPIO.output(12, GPIO.HIGH)
    time.sleep(2)
    GPIO.output(12, GPIO.LOW)
    time.sleep(2)

    GPIO.output(13, GPIO.HIGH)
    time.sleep(2)
    GPIO.output(13, GPIO.LOW)
    time.sleep(2)

    GPIO.output(18, GPIO.HIGH)
    time.sleep(2)
    GPIO.output(18, GPIO.LOW)
    time.sleep(2)
