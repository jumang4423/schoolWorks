#config: utf-8
import RPi.GPIO as GPIO
import time

#macro
button = 25
led=24

#settings
GPIO.setmode(GPIO.BCM)
GPIO.setup(led, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(button, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

print("push button")

while True:
    btn = GPIO.input(button)
    if btn == True:
        GPIO.output(led, 1)
        time.sleep(5)
        GPIO.output(led, 0)
        break
    time.sleep(1)

GPIO.cleanup()
