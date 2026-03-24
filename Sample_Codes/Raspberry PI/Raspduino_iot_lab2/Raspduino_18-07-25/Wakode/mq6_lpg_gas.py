import spidev
import time
import paho.mqtt.client as mqtt
import json

THINGSBOARD_HOST = 'demo.thingsboard.io'
Token = 'bdThfGxgIYh7TmSuLrM8'
client = mqtt.Client()

# Set access token
client.username_pw_set(Token)

# Connect to ThingsBoard using default MQTT port and 60 seconds keepalive interval
client.connect(THINGSBOARD_HOST, 1883, 60)

client.loop_start()

spi = spidev.SpiDev() # Open SPI bus
spi.open(0, 1)
spi.max_speed_hz = 100000

Data = {"Sensor_Type": "MQ6_LPG_sensor"}

def ReadChannel(channel): # read channel (0-7) from MCP3208
    adc = spi.xfer([6 | (channel & 4) >> 2, (channel & 3) << 6, 0],5,1000)
    data = ((adc[1] & 15) << 8) + adc[2]
    return data

while(True):
    value = ReadChannel(3)
    print(f"MQ6_LPG_sensor: {value}")
    print("----------------------")
    print("                 ")
    
    Data["MQ6_LPG_val"] = value
    client.publish('v1/devices/me/telemetry',json.dumps(Data), 1)
    time.sleep(5)

