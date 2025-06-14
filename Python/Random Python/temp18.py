#LED
import RPI.GPIO as GPIO
import time
led=5

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(led,GPIO.OUT)
GPIO.output(led,GPIO.HIGH)

def blink():
    GPIO.output(led,GPIO.HIGH)
    time.sleep(1)
    GPIO.output(led,GPIO.LOW)
    time.sleep(1)

def destroy():
    GPIO.output(led,GPIO.LOW)
    GPIO.cleanup()

if __name__ == "__main__":
    try:
        while True:
            blink()
    except KeyboardInterrupt:
        destroy()


#switch
import RPI.GPIO as GPIO
import time
button=16
led=18

def setup():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(button,GPIO.IN,PULL_UP_DOWN=GPIO.PUD_UP)
    GPIO.setup(led,GPIO.OUT)

def loop():
    button_state=GPIO.input(button)
    if button_state==True:
        GPIO.output(led,True)
        print('Button Pressed')
        while GPIO.input(button)==False:
            time.sleep(0.1)
    else:
        GPIO.output(led,False)

def endpg():
    GPIO.output(led,False)
    GPIO.cleanup()

if __name__ == '__main__':
    setup()
    try:
        loop()
    except KeyboardInterrupt:
        endpg()


#ldr
        
import RPI.GPIO as GPIO
import time
LDR_PIN=6

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(6,GPIO.IN)

def rc_time(ptc):
    count=0
    GPIO.setup(ptc,GPIO.OUT)
    GPIO.setup(ptc,GPIO.LOW)
    time.sleep()
    GPIO.output(ptc,GPIO.IN)
    while(GPIO.input(ptc)==GPIO.LOW):
        count+=1
    return count

if __name__ == "__main__":
    try:
        while True:
            print(rc_time(LDR_PIN))
    except KeyboardInterrupt:
        GPIO.cleanup()
        