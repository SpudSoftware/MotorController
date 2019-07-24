// test.cpp

#include <pigpio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

const int kLED_A = 21;
const int kMotorA_IN1 = 16;
const int kMotorA_IN2 = 20;
const int kMotorA_PWM = 19;
int main(int argc, char** argv)
{
	unsigned int Sleep_microsec = 2.0 * 1.0E6;
   cout << "This is a test." << endl;
   
	if (gpioInitialise() < 0)
	{
	   // pigpio initialisation failed.
	}
	else
	{
	   // pigpio initialised okay.
	   
	   gpioSetMode(kMotorA_IN1, PI_OUTPUT);  // Motor A
	   gpioSetMode(kMotorA_PWM, PI_OUTPUT);  // PWM
	   gpioSetMode(kMotorA_IN2, PI_OUTPUT);  // Motor B
	   gpioSetMode(kLED_A, PI_OUTPUT); 
	   
      gpioPWM(kMotorA_PWM, 60); /* 192/255 = 75% */	  
      
       
	   gpioWrite(kLED_A, 1); // LED ON
      
      gpioWrite(kMotorA_IN1, 1); 
      gpioWrite(kMotorA_IN2, 0); 
	   usleep(Sleep_microsec);
	   
      gpioPWM(kMotorA_PWM, 255); /* 192/255 = 75% */	  
	   gpioWrite(kLED_A, 0); // LED OFF
      gpioWrite(kMotorA_IN1, 0); 
      gpioWrite(kMotorA_IN2, 1); 
	   usleep(Sleep_microsec);
      
	   gpioWrite(kLED_A, 1); // LED ON
      gpioWrite(kMotorA_IN1, 1); 
      gpioWrite(kMotorA_IN2, 0); 
 	   usleep(100000);
     
      gpioPWM(kMotorA_PWM, 0); /* 192/255 = 75% */	  
	   gpioWrite(kLED_A, 0); // LED OFF
	   
	}	
	
	gpioTerminate();
	
   return 1;
}
