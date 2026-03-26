from machine import Pin
from time import sleep_ms
# Control pins
rs = Pin(0, Pin.OUT)
en = Pin(1, Pin.OUT)
# Data pins D0-D7
d0 = Pin(2, Pin.OUT)
d1 = Pin(3, Pin.OUT)
d2 = Pin(4, Pin.OUT)
d3 = Pin(5, Pin.OUT)
d4 = Pin(6, Pin.OUT)
d5 = Pin(7, Pin.OUT)
d6 = Pin(8, Pin.OUT)
d7 = Pin(9, Pin.OUT)

data_pins = [d0,d1,d2,d3,d4,d5,d6,d7]
def send_byte(value, mode):

    rs.value(mode)

    for i in range(8):
        data_pins[i].value((value >> i) & 1)

    en.value(1)
    sleep_ms(2)
    en.value(0)
    sleep_ms(2)

def lcd_command(cmd):
    send_byte(cmd,0)

def lcd_data(data):
    send_byte(data,1)

def lcd_init():
    sleep_ms(50)

    lcd_command(0x38)   # 8-bit mode
    lcd_command(0x0C)   # Display ON
    lcd_command(0x01)   # Clear display
    lcd_command(0x06)   # Cursor move right

lcd_init()
message = "LOGSUN"
print(message)
for ch in message:
    lcd_data(ord(ch))
