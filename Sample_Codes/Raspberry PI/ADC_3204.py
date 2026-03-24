import spidev
import time

# Initialize SPI
spi = spidev.SpiDev()
spi.open(0, 0)  # (bus, device) = (0, 0) for CE0
spi.max_speed_hz = 1000000  # 1 MHz (adjust as needed)

def read_channel(channel):
    # MCP3204 expects 3 bytes per transfer:
    # Byte 1: Start bit (1) + single-ended (1) + channel bits (D1/D0)
    # Byte 2: Dummy bits
    # Byte 3: Don't care (used to receive data)
    if channel < 0 or channel > 3:
        raise ValueError("Channel must be 0-3 for MCP3204")
    adc = spi.xfer2([1, (8 | (channel << 1)), 0])
    data = ((adc[1] & 3) << 8) + adc[2]
    return data

try:
    while True:
        channel = 0  # Read CH0 (0-3 for MCP3204)
        value = read_channel(channel)
        voltage = (value * 3.3) / 4095  # Convert to voltage (12-bit resolution)
        print(f"CH{channel}: Value = {value}, Voltage = {voltage:.2f}V")
        time.sleep(1)
except KeyboardInterrupt:
    spi.close()