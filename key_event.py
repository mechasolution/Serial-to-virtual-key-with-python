import ctypes
import serial
user = ctypes.windll.user32

ser = serial.Serial()
ser.port = 'COM33' # put your arduino COM port
ser.baudrate = 9600 # put your arduino baudrate
ser.open()
while (True):
    if(ser.inWaiting() > 0):
        HEX = ord(ser.read())
        user.keybd_event(HEX,0,1,0) # press! 
        user.keybd_event(HEX,0,2,0) # up!


# use what do you want to do
