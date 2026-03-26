from machine import Pin
import time

# Segment pins (a,b,c,d,e,f,g)
segments = [
    Pin(12, Pin.OUT),
    Pin(13, Pin.OUT),
    Pin(20, Pin.OUT),
    Pin(21, Pin.OUT),
    Pin(16, Pin.OUT),
    Pin(17, Pin.OUT),
    Pin(6, Pin.OUT)
]

# Digit control pins (transistors)
digits = [
    Pin(19, Pin.OUT),
    Pin(16, Pin.OUT),
    Pin(18, Pin.OUT),
    Pin(17, Pin.OUT)
]

# Hexadecimal patterns for Common Anode
hex_patterns = [
[0,0,0,0,0,0,1], #0
[1,0,0,1,1,1,1], #1
[0,0,1,0,0,1,0], #2
[0,0,0,0,1,1,0], #3
[1,0,0,1,1,0,0], #4
[0,1,0,0,1,0,0], #5
[0,1,0,0,0,0,0], #6
[0,0,0,1,1,1,1], #7
[0,0,0,0,0,0,0], #8
[0,0,0,0,1,0,0], #9
[0,0,0,1,0,0,0], #A
[1,1,0,0,0,0,0], #b
[0,1,1,0,0,0,1], #C
[1,0,0,0,0,1,0], #d
[0,1,1,0,0,0,0], #E
[0,1,1,1,0,0,0]  #F
]

def show_digit(value):
    pattern = hex_patterns[value]
    for i in range(7):
        segments[i].value(pattern[i])

while True:

    for num in range(16):   # 0 → F

        for _ in range(30):

            for i in range(4):

                # turn OFF all digits
                for d in digits:
                    d.value(0)

                show_digit(num)

                # turn ON selected digit
                digits[i].value(1)

                time.sleep_ms(5)
