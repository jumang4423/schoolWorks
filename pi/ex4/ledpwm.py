import RPi.GPIO as GPIO
import time
led = 24

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(led, GPIO.OUT, initial=GPIO.LOW)

p = GPIO.PWM(led, 1000)
p.start(0)

dutyratio = 0
for i in range(3):
    for j in range(5):
        dutyratio += 10
        p.ChangeDutyCycle(dutyratio)
        time.sleep(1)
    for j in range(5):
        dutyratio -= 10
        p.ChangeDutyCycle(dutyratio)
        time.sleep(1)

p.stop()
GPIO.cleanup()