import serial
import time
# configure the serial connections (the parameters differs on the device you are connecting to)
ser = serial.Serial('/dev/ttyACM0',9600)
time.sleep(3)
ser.isOpen()
ser.write('0')
ser.close() 
