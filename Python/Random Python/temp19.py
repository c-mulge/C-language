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
            time.sleep(0.2)
    else:
        GPIO.output(led,False)

def endpg():
    GPIO.output(led,False)
    GPIO.cleanup()

if __name__=="_main_":
    setup()
    try:
        loop()
    except KeyboardInterrupt:
        endpg()

