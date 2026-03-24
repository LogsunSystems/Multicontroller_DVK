import serial
import  RPi.GPIO as GPIO
import os
import time
GPIO.setmode(GPIO.BOARD)
port = serial.Serial("/dev/ttyAMA0", baudrate=9600)
while(True):
        rcv = port.read(10)
        print(rcv)

