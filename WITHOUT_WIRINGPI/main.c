#include <stdio.h>
#include "library.h"

int main(int argc, char **argv)
{
	wiringPiSetup();
	system("sudo gpio load i2c");
	//pinMode (0, OUTPUT);
	//printf("%c\n",test('A'));

	piGlowSetup(1);
	while(1)
	{
		int i=0;
		for(i; i<=5; i++)
		{
			piGlowRing(i, 60);
			delay(2000);
			system("sudo piglow off");
		}
		//~ i=0;
		system("sudo piglow off");
	}
}

