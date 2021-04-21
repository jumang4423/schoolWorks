#config: utf-8
import RPi.GPIO as GPIO
import time

#macro
led=24

#settings
GPIO.setmode(GPIO.BCM)
GPIO.setup(led, GPIO.OUT, initial=GPIO.LOW)

#10 times turn on/off
for i in range(10): 
    GPIO.output(led, 1)
    time.sleep(1)
    GPIO.output(led, 0)
    time.sleep(1)

GPIO.cleanup()
