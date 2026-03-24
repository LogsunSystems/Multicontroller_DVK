import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BOARD)

GPIO.setup(18, GPIO.OUT)
GPIO.setup(16, GPIO.OUT)
GPIO.setup(15, GPIO.OUT)

while(True):
    GPIO.output(18, GPIO.HIGH)
    time.sleep(2)
    GPIO.output(18, GPIO.LOW)
    time.sleep(2)

    GPIO.output(16, GPIO.HIGH)
    time.sleep(2)
    GPIO.output(16, GPIO.LOW)
    time.sleep(2)

    GPIO.output(15, GPIO.HIGH)
    time.sleep(2)
    GPIO.output(15, GPIO.LOW)
    time.sleep(2)
