import spidev
import time

# Initialize SPI
spi = spidev.SpiDev()
spi.open(0, 0)  # (bus, device) = (0, 0) for CE0
spi.max_speed_hz = 1000000  # 1 MHz (adjust as needed)

def read_channel(channel):
    # MCP3208 expects 3 bytes per transfer:
    # Byte 1: Start bit (1) + single-ended (1) + channel MSB (D2)
    # Byte 2: Channel LSB (D1/D0) + dummy bits
    # Byte 3: Don't care (used to receive data)
    adc = spi.xfer2([1, (8 + channel) << 4, 0])
    data = ((adc[1] & 3) << 8) + adc[2]
    return data

try:
    while True:
        channel = 0  # Read CH0 (adjust for your sensor)
        value = read_channel(channel)
        voltage = (value * 3.3) / 4095  # Convert to voltage (12-bit resolution)
        print(f"CH{channel}: Value = {value}, Voltage = {voltage:.2f}V")
        time.sleep(1)
except KeyboardInterrupt:
    spi.close()
