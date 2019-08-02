from gpiozero import PWMOutputDevice
from gpiozero import Robot
from time import sleep
from gpiozero import LED

led1 = LED(21)
#robot1 = Robot(right=(16, 20), left=(6,5))
robot1 = Robot(left=(16, 20), right=(6,5))

PwmRight = PWMOutputDevice(19)
PwmLeft  = PWMOutputDevice(13)

PwmRight.frequency = 1000
PwmRight.value = 0.25

PwmLeft.frequency = 1000
PwmLeft.value = 0.25

led1.on()
robot1.forward()
sleep(1)
led1.off()
robot1.left()
sleep(1)
#robot1.right()
sleep(1)
#robot1.backward()
led1.on()
sleep(1)
robot1.stop()
led1.off()

#const int kMotorA_IN1 = 16;
#const int kMotorA_IN2 = 20;
#const int kMotorA_PWM = 19;
#const int kMotorB_IN3 =  6;
#const int kMotorB_IN4 =  5;
#const int kMotorB_PWM = 13;
