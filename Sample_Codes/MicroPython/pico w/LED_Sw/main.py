from machine import Pin

# Create list for 8 switches (inputs)
switches = [
    Pin(12, Pin.IN, Pin.PULL_DOWN),
    Pin(13, Pin.IN, Pin.PULL_DOWN),
    Pin(20, Pin.IN, Pin.PULL_DOWN),
    Pin(21, Pin.IN, Pin.PULL_DOWN),
    Pin(16, Pin.IN, Pin.PULL_DOWN),
    Pin(17, Pin.IN, Pin.PULL_DOWN),
    Pin(18, Pin.IN, Pin.PULL_DOWN),
    Pin(19, Pin.IN, Pin.PULL_DOWN)
]

# Create list for 8 LEDs (outputs)
leds = [
    Pin(2, Pin.OUT),
    Pin(3, Pin.OUT),
    Pin(6, Pin.OUT),
    Pin(7, Pin.OUT),
    Pin(8, Pin.OUT),
    Pin(9, Pin.OUT),
    Pin(10, Pin.OUT),
    Pin(11, Pin.OUT)
]
    
while True:
    
    for i in range(8):
        
        if switches[i].value() == 1:   # If switch pressed
            leds[i].toggle()           # Blink LED
        else:
            leds[i].value(0)           # LED OFF
