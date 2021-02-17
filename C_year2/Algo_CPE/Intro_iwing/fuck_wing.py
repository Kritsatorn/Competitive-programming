from machine import Pin
led = Pin(2, Pin.OUT)
led.value(1) # turn LED on
led.value(0) # turn LED off