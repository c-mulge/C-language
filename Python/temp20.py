import RPI.GPIO as GPIO
import time
LDR_PIN=6
GPIO.setwarning(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(6,GPIO.IN)

def rc_time(ptc):
    count=0
    GPIO.setup(ptc,GPIO.OUT)
    GPIO.setup(ptc,GPIO.LOW)
    time.sleep(0.1)
    GPIO.setup(ptc,GPIO.IN)
    while(GPIO.input(ptc)==GPIO.LOW):
        count+=1
    return count

if __name__ == "__main__":
    try:
        while True:
            print(rc_time(LDR_PIN))
    except KeyboardInterrupt:
        GPIO.cleanup()

        