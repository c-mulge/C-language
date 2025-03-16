import RPI.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
PIR=21
BUZ=22
GPIO.setup(PIR,GPIO.IN)
GPIO.setup(BUZ,GPIO.OUT)

if __name__ =='_main_':
    try:
        while True:
            PIR_State=GPIO.input(PIR)
            if PIR_State == True:
                print('Motion detected')
                GPIO.output(BUZ,GPIO.HIGH)
                time.sleep(0.5)
                GPIO.output(BUZ,GPIO.LOW)
                time.sleep(1)
            else:
                    print('No motion')
    
    except KeyboardInterrupt:
         GPIO.cleanup()


import RPI.GPIO as GPIO
import time
PIR=21
BUZ=22
GPIO.setmode(GPIO.BCM)
GPIO.setup(PIR,GPIO.IN)
GPIO.setup(BUZ,GPIO.OUT)

if __name__ == '_main_':
    try:
        while True:
            PIR_STATE=GPIO.input(PIR)
            if PIR_STATE == True:
                print("Motion detected")
                GPIO.output(BUZ,GPIO.HIGH)
                time.sleep(0.1)
                GPIO.output(BUZ,GPIO.LOW)
                time.sleep(0.1)
            else:
                print("No motion")

    except KeyboardInterrupt:
        GPIO.cleanup()



                    