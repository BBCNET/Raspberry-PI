/*
 * unbenannt.c
 * 
 * Copyright 2014  <pi@raspberrypi>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA. 
 * 
 * 
 */


#include <stdio.h>
#include <wiringPi.h>
#include <piGlow.h>
#include <sn3218.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define PIGLOW_BASE     577
#define PIGLOW_RED      0
#define PIGLOW_YELLOW   1
#define PIGLOW_ORANGE   2
#define PIGLOW_GREEN    3
#define PIGLOW_BLUE     4
#define PIGLOW_WHITE    5

static int leg0 [6] = {  6,  7,  8,  5,  4,  9 } ;
static int leg1 [6] = { 17, 16, 15, 13, 11, 10 } ;
static int leg2 [6] = {  0,  1,  2,  3, 14, 12 } ;
void piGlowSetup (int clear)
{
  sn3218Setup (PIGLOW_BASE) ;

  if (clear)
  {
    piGlowLeg (0, 0) ;
    piGlowLeg (1, 0) ;
    piGlowLeg (2, 0) ;
  }
}

void piGlowRing (const int ring, const int intensity)
{
  if ((ring < 0) || (ring > 5))
    return ;

  analogWrite (PIGLOW_BASE + leg0 [ring], intensity) ;
  analogWrite (PIGLOW_BASE + leg1 [ring], intensity) ;
  analogWrite (PIGLOW_BASE + leg2 [ring], intensity) ;
}

int main(int argc, char **argv)
{
	wiringPiSetup();
	system("sudo gpio load i2c");
	//pinMode (0, OUTPUT);
	//printf("%c\n",test('A'));

	piGlowSetup(TRUE);
	while(1)
	{
		int i=5;
		for(i; i>=0; i--)
		{
			piGlowRing(i, 60);
			delay(2000);
			system("piglow off");
		}
		//~ i=0;
		system("piglow off");
	}
}

