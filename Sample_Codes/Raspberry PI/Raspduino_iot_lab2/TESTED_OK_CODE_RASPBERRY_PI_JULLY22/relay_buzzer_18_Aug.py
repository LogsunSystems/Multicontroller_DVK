import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

GPIO.setup(40, GPIO.OUT)
GPIO.setup(15, GPIO.OUT)
GPIO.output(15, GPIO.LOW)
GPIO.output(40, GPIO.LOW)

while(True):
    GPIO.output(40, GPIO.HIGH)
    GPIO.output(15, GPIO.HIGH)
    time.sleep(2)
    print("IN1")
    GPIO.output(40, GPIO.LOW)
    GPIO.output(15, GPIO.LOW)
    time.sleep(2)
    print("IN2")
