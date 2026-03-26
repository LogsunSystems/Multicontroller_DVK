from machine import Pin

# Create list for 8 switches (inputs)
switches = [
    Pin(4, Pin.IN, Pin.PULL_DOWN),
    Pin(17, Pin.IN, Pin.PULL_DOWN),
    Pin(16, Pin.IN, Pin.PULL_DOWN),
    Pin(5, Pin.IN, Pin.PULL_DOWN),
    Pin(18, Pin.IN, Pin.PULL_DOWN),
    Pin(19, Pin.IN, Pin.PULL_DOWN),
    Pin(23, Pin.IN, Pin.PULL_DOWN),
    Pin(15, Pin.IN, Pin.PULL_DOWN)
]

# Create list for 8 LEDs (outputs)
leds = [
    Pin(12, Pin.OUT),
    Pin(13, Pin.OUT),
    Pin(14, Pin.OUT),
    Pin(25, Pin.OUT),
    Pin(26, Pin.OUT),
    Pin(27, Pin.OUT),
    Pin(32, Pin.OUT),
    Pin(33, Pin.OUT)
]

while True:
    
    for i in range(8):
        
        if switches[i].value() == 1:   # If switch pressed
            leds[i].toggle()           # Blink LED
        else:
            leds[i].value(0)           # LED OFF
