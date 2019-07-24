// test.cpp

#include <pigpio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	unsigned int Sleep_microsec = 1.0 * 1.0E6;
   cout << "This is a test." << endl;
   
	if (gpioInitialise() < 0)
	{
	   // pigpio initialisation failed.
	}
	else
	{
	   // pigpio initialised okay.
	   
	   gpioSetMode(21, PI_OUTPUT); // Set GPIO18 as output.
	   
	   
	   gpioWrite(21, 1); // Set GPIO24 high.
	   
	   usleep(Sleep_microsec);
	   
	   gpioWrite(21, 0); // Set GPIO24 high.
	   
	   
	}	
	
	gpioTerminate();
	
   return 1;
}
