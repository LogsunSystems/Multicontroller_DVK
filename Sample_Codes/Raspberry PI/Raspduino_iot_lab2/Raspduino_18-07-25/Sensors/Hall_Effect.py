import RPi.GPIO as gpio
import time
import paho.mqtt.client as mqtt
import json

sensor_Pin = 5

THINGSBOARD_HOST = 'demo.thingsboard.io'
Token = 'bdThfGxgIYh7TmSuLrM8'
client = mqtt.Client()

# Set access token
client.username_pw_set(Token)

# Connect to ThingsBoard using default MQTT port and 60 seconds keepalive interval
client.connect(THINGSBOARD_HOST, 1883, 60)

client.loop_start()

Data = {"Sensor_Type": "Magnet"}

gpio.setmode(gpio.BCM)
gpio.setup(sensor_Pin,gpio.IN)

while(True):
    value = gpio.input(sensor_Pin)
    print(f"Hall_Effect_Sensor: {value}")
    print("----------------------")
    print("                 ")
    
    Data["Hall_Effect"] = value
    client.publish('v1/devices/me/telemetry',json.dumps(Data), 1)
    time.sleep(5)
