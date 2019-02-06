/* 
	FPS_Blink.ino - Library example for controlling the GT-511C3 Finger Print Scanner (FPS) using (ATmega32U4 Processor) Arduino Board Leonardo, Arduino Board Micro and Arduino Board Yun.
	Created by Abhishek Bhakat, 21st December, 2016
 
	This simple sketch turns the LED on and off similar to the Arduino blink sketch.
	It is used to show that communications are working.
*/

#include "FPS_GT511C3.h"

// Hardware setup - FPS connected to:
//	  digital pin 0(arduino rx, fps tx)
//	  digital pin 1(arduino tx - 560ohm resistor fps tx - 1000ohm resistor - ground)
//		this brings the 5v tx line down to about 3.2v so we dont fry our fps

FPS_GT511C3 fps;

void setup()
{
	Serial.begin(9600);
	fps.UseSerialDebug = true; // so you can see the messages in the serial debug screen
	fps.Open();
}


void loop()
{
	// FPS Blink LED Test
	fps.SetLED(true); // turn on the LED inside the fps
	delay(1000);
	fps.SetLED(false);// turn off the LED inside the fps
	delay(1000);
}
