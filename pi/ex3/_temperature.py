import RPi.GPIO as GPIO
import dht11
import time
import datetime

GPIO.setwarinings(True)
GPIO.setmode(GPIO.BCM)

instance = dht11.DHT11(pin=14)

try:
    while True:
        result = instance.read()
        if result.is_vaild():
            print("Last vaild input: " + str(datetime.datetime.now()))

            print("Temperature: %-3.1f C" % result.temperature)
            print("HUmidity: %-3.1f %%" % result.humidity)

        time.sleep(6)

except KeyboardInterrupt:
    print("Cleanup")
    GPIO.cleanup()
