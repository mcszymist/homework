# By Tyler J Roberts
# This program uses serial to comunicate with a arduino mega to turn
# a LED on and off whenever the camera notices the change to switch.
# It does this to calulate the time inbetween exposures to claculate
# the speed of the camera.
# The webcam I used was my ASUS laptop six year old webcam. 


# +------------RESULTS-------------+
# |  Time:      0.0666110515594    |
# |  Frames:    2                  |
# |  Error:     1 frame or .03s    |
# +--------------------------------+

import cv2      #openCV for python
import time     
import serial   #pyserial

ser = serial.Serial('/dev/ttyACM0',9600)
time.sleep(3)  # have to sleep here as the arduino is still booting.
ser.isOpen()

cv2.namedWindow("preview")
vc = cv2.VideoCapture(0)

if vc.isOpened(): # try to get the first frame
    rval, frame = vc.read()
else:
    rval = False
framesPast = 0
switchingW = True
started = False

while rval:
    if started == False:
        start = time.time()
        framesPast = 0
        started = True
    rval, frame = vc.read()
    framesPast = framesPast + 1
    if frame[240,300][0] < 150 and frame[240,300][1] < 150 and frame[240,300][2] < 150 and switchingW == False:
        print time.time() - start
        ser.write('1')
        print framesPast
        switchingW = True
        started = False
        
    if frame[240,300][0] > 150 and frame[240,300][1] > 150 and frame[240,300][2] > 150 and switchingW == True:
        print time.time() - start
        ser.write('0')
        print framesPast
        switchingW = False
        started = False
    # ser.write('2') debug command
    # print ser.readline() debug command
# cleanup
cv2.destroyWindow("preview")
vc.release()
ser.close() 

