import RPi.GPIO as GPIO
import time
servo = 24
GPIO.setmode(GPIO.BCM)
GPIO.setup(servo, GPIO.OUT, initial=GPIO.LOW)

p = GPIO.PWM(servo, 50)

p.start(0)

p.ChangeDutyCycle(7.5)
time.sleep(1)
for i in range(3):
    p.ChangeDutyCycle(2.5)
    time.sleep(1)
    p.ChangeDutyCycle(7.5)
    time.sleep(1)
    p.ChangeDutyCycle(12)
    time.sleep(1)
    p.ChangeDutyCycle(7.5)
    time.sleep(1)

p.stop()
GPIO.cleanup()
