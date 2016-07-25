import ctypes
import serial
user = ctypes.windll.user32

ser = serial.Serial()
ser.port = 'COM33'
ser.baudrate = 9600
ser.open()
while (True):
    if(ser.inWaiting() > 0):
        HEX = ord(ser.read())
        user.keybd_event(HEX,0,1,0)
        user.keybd_event(HEX,0,2,0)
