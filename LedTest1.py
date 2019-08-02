from gpiozero import LED
from time import sleep

Led1 = LED(21)

while True:
   Led1.on()
   sleep(1)
   Led1.off()
   sleep(1)
