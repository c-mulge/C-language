import RPI.GPIO as GPIO
import time
import Adafruit_DHT

SENSOR=Adafruit_DHT.DHT11
DHTOUT=18

GPIO.setmode(GPIO,BCM)

if __name__ == "__main__":
    try:
        while True:
            humidity,temperature=Adafruit_DHT.read_retry(SENSOR,DHTOUT)
            if humidity is not None and temperature is not None:
                humidity=round(humidity, 2)
                temperature=round(temperature, 2)
                print('Temperature={0:01f}*c Humidity={1:01f}%'.format(temperature, humidity))
            else:
                print('Can not connect to sensor')
            time.sleep(1)
    except KeyboardInterrupt:
        GPIO.cleanup()
        