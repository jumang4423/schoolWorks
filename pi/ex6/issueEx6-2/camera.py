#coding: utf-8
import webiopi
import os

#save directory
SAVEDIR = '/home/pi/schoolWorks/pi/ex6'
@webiopi.macro
def camera(no):
    #filename
    filename = SAVEDIR + '/camera_' + no + '.jpg'
    #taking a photo
    command = 'fswebcam -r 320x240 -d /dev/video0 ' + filename
    os.system(command)
    #writing to disk cache
    os.system('sync')