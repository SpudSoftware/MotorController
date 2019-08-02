// test.cpp

#include <pigpio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

const int kLED_A = 21;
const int kMotorA_IN1 = 16;
const int kMotorA_IN2 = 20;
const int kMotorA_PWM = 19;

const int kMotorB_IN3 =  6;
const int kMotorB_IN4 =  5;
const int kMotorB_PWM = 13;
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
	   
	   gpioSetMode(kMotorA_IN1, PI_OUTPUT);  // Motor A1
	   gpioSetMode(kMotorA_IN2, PI_OUTPUT);  // Motor A2
	   gpioSetMode(kMotorA_PWM, PI_OUTPUT);  // PWM
      
	   gpioSetMode(kMotorB_IN3, PI_OUTPUT);  // Motor B3
	   gpioSetMode(kMotorB_IN4, PI_OUTPUT);  // Motor B4
	   gpioSetMode(kMotorB_PWM, PI_OUTPUT);  // PWM
      
	   gpioSetMode(kLED_A, PI_OUTPUT); 
	   
      gpioPWM(kMotorA_PWM, 60); /* 192/255 = 75% */	  
      gpioPWM(kMotorB_PWM, 60); /* 192/255 = 75% */	  
     
       
	   gpioWrite(kLED_A, 1); // LED ON
      
      gpioWrite(kMotorA_IN1, 1); 
      gpioWrite(kMotorA_IN2, 0); 

      gpioWrite(kMotorB_IN3, 1); 
      gpioWrite(kMotorB_IN4, 0); 

	   usleep(Sleep_microsec);
	   
      gpioPWM(kMotorA_PWM, 255); /* 192/255 = 75% */	  
      gpioPWM(kMotorB_PWM, 255); /* 192/255 = 75% */	  
      
	   gpioWrite(kLED_A, 0); // LED OFF
      gpioWrite(kMotorA_IN1, 0); 
      gpioWrite(kMotorA_IN2, 1); 
      
      gpioWrite(kMotorB_IN3, 0); 
      gpioWrite(kMotorB_IN4, 1); 

	   usleep(Sleep_microsec);
      
	   gpioWrite(kLED_A, 1); // LED ON
      gpioWrite(kMotorA_IN1, 1); 
      gpioWrite(kMotorA_IN2, 0); 
      
      gpioWrite(kMotorB_IN3, 1); 
      gpioWrite(kMotorB_IN4, 0); 

 	   usleep(100000);
     
      gpioPWM(kMotorA_PWM, 0); /* 192/255 = 75% */	  
      gpioPWM(kMotorB_PWM, 0); /* 192/255 = 75% */	  
	   gpioWrite(kLED_A, 0); // LED OFF
	   
	}	
	
	gpioTerminate();
	
   return 1;
}
