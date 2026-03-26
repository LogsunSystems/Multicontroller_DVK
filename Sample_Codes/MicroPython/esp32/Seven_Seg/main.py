from machine import Pin
import time

# Segment pins (a,b,c,d,e,f,g)
segments = [
    Pin(12, Pin.OUT),
    Pin(13, Pin.OUT),
    Pin(14, Pin.OUT),
    Pin(25, Pin.OUT),
    Pin(26, Pin.OUT),
    Pin(27, Pin.OUT),
    Pin(32, Pin.OUT),
    Pin(33,Pin.OUT)
]

# Digit control pins (transistors)
digits = [
    Pin(23, Pin.OUT),
    Pin(19, Pin.OUT),
    Pin(18, Pin.OUT),
    Pin(5, Pin.OUT)
]

# Hexadecimal patterns for Common Anode
hex_patterns = [
[0,0,0,0,0,0,1,1], #0
[1,0,0,1,1,1,1,1], #1
[0,0,1,0,0,1,0,1], #2
[0,0,0,0,1,1,0,1], #3
[1,0,0,1,1,0,0,1], #4
[0,1,0,0,1,0,0,1], #5
[0,1,0,0,0,0,0,1], #6
[0,0,0,1,1,1,1,1], #7
[0,0,0,0,0,0,0,1], #8
[0,0,0,0,1,0,0,1], #9
[0,0,0,1,0,0,0,1], #A
[1,1,0,0,0,0,0,1], #b
[0,1,1,0,0,0,1,1], #C
[1,0,0,0,0,1,0,1], #d
[0,1,1,0,0,0,0,1], #E
[0,1,1,1,0,0,0,1]  #F
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
