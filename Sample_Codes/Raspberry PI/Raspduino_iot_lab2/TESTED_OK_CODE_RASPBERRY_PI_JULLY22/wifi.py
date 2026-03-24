import serial
import time
port = serial.Serial("/dev/ttyS0", baudrate=9600, timeout=3.0)
def readlineCR(port):
    rv=" "
    #while 1:
    rv = port.read(5096)
    #rv +ch
    return rv
isConnected=True;
while isConnected:
    port.write(b"AT\r\n")
    returnedData=readlineCR(port)
    print(returnedData)
    if b'OK' not in returnedData:
        print("Module not connected")
        time.sleep(60)
    else:
        print("Device connected")
        isConnected=False
port.write("AT+CWMODE=1\r\n")
returnedData=readlineCR(port)
print(returnedData)
if "OK"  not in returnedData:
    print("unable config client")
else:
    print("configured as STA")
port.write("AT+RST\r\n")
returnedData=readlinrCR(port)
print(returnedData)
if "OK" not in returnedData:
    print("WiFi not reset")
else:
    print("Wifi reset")