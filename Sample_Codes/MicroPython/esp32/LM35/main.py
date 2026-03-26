from machine import ADC, Pin
import time

# Configure ADC on pin 33
adc = ADC(Pin(33))
adc.atten(ADC.ATTN_11DB)   # allows full range ~0-3.6V
adc.width(ADC.WIDTH_12BIT) # 12-bit resolution (0-4095)

while True:
    # Read raw ADC value
    raw = adc.read()
    
    # Convert to voltage (in volts)
    voltage = (raw / 4095) * 3.3   # assuming 3.3V reference
    
    # Convert voltage to temperature (°C)
    temperature = voltage * 100    # because 10mV per °C
    
    print("Temperature: {:.2f} °C".format(temperature))
    time.sleep(1)