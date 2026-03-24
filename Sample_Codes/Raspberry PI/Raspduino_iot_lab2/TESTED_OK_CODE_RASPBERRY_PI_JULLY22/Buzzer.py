import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

Buzzer = 5

GPIO.setup(Buzzer, GPIO.OUT)
GPIO.output(Buzzer, GPIO.LOW)

while(True):
    GPIO.output(Buzzer, GPIO.HIGH)
    time.sleep(2)
    GPIO.output(Buzzer, GPIO.LOW)
    time.sleep(2)

