import RPi.GPIO as IO            # calling for header file which helps us use GPIO’s of PI
import time                              # calling for time to provide delays in program
DISPLAY = [0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10]            # string of characters storing PORT values for each digit.
IO.setwarnings(False)            # do not show any warnings
IO.setmode (IO.BCM)           # programming the GPIO by BCM pin numbers. (like PIN29 as‘GPIO5’)
IO.setup(5,IO.OUT)             # initialize GPIO Pins as outputs
IO.setup(6,IO.OUT)
IO.setup(13,IO.OUT)
IO.setup(19,IO.OUT)
IO.setup(26,IO.OUT)
IO.setup(16,IO.OUT)
IO.setup(20,IO.OUT)
IO.setup(21,IO.OUT)

IO.setup(10,IO.OUT)
IO.setup(9,IO.OUT)
IO.setup(11,IO.OUT)
IO.setup(7,IO.OUT)

IO.output(10,1)
IO.output(9,1)
IO.output(11,1)
IO.output(7,1)
def PORT(pin):                    # assigning GPIO logic by taking 'pin' value
    if(pin&0x01 == 0x01):
        IO.output(5,1)            # if  bit0 of 8bit 'pin' is true, pull PIN13 high
    else:
        IO.output(5,0)            # if  bit0 of 8bit 'pin' is false, pull PIN13 low
    if(pin&0x02 == 0x02):
        IO.output(6,1)             # if  bit1 of 8bit 'pin' is true, pull PIN6 high
    else:
        IO.output(6,0)            #if  bit1 of 8bit 'pin' is false, pull PIN6 low
    if(pin&0x04 == 0x04):
        IO.output(13,1)
    else:
        IO.output(13,0)
    if(pin&0x08 == 0x08):
        IO.output(19,1)
    else:
        IO.output(19,0)   
    if(pin&0x10 == 0x10):
        IO.output(26,1)
    else:
        IO.output(26,0)
    if(pin&0x20 == 0x20):
        IO.output(16,1)
    else:
        IO.output(16,0)
    if(pin&0x40 == 0x40):
        IO.output(20,1)
    else:
        IO.output(20,0)
    if(pin&0x80 == 0x80):
        IO.output(21,1)            # if  bit7 of 8bit 'pin' is true, pull PIN12 high
    else:
        IO.output(21,0)            # if  bit7 of 8bit 'pin' is false, pull PIN12 low
while 1:
    for x in range(10):            # execute the loop ten times incrementing x value from zero to nine
        pin = DISPLAY[x]        # assigning value to 'pin' for each digit
        PORT(pin);                  # showing each digit on display 
        time.sleep(1)