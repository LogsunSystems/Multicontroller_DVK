from machine import Pin
from time import sleep
IR_Pin = 33
Pin(IR_Pin,Pin.IN)

while True:
    if(Pin(IR_Pin).value() ==1):
        print("Obstacle Detected\r\n")
    else:
        print("No Obstacle\r\n")
    sleep(1)