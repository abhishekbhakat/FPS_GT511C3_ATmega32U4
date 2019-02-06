/* 
  FPS_IDFinger.ino - Library example for controlling the GT-511C3 Finger Print Scanner (FPS) using (ATmega32U4 Processor) Arduino Board Leonardo, Arduino Board Micro and Arduino Board Yun.
  Created by Abhishek Bhakat, 21st December, 2016

	This sketch will attempt to identify a previously enrolled fingerprint.
*/

#include "FPS_GT511C3.h"

// Hardware setup - FPS connected to:
//    digital pin 0(arduino rx, fps tx)
//    digital pin 1(arduino tx - 560ohm resistor fps tx - 1000ohm resistor - ground)
//    this brings the 5v tx line down to about 3.2v so we dont fry our fps

FPS_GT511C3 fps;

void setup()
{
	Serial.begin(9600);
	delay(100);
	fps.Open();
	fps.SetLED(true);
}

void loop()
{

	// Identify fingerprint test
	if (fps.IsPressFinger())
	{
		fps.CaptureFinger(false);
		int id = fps.Identify1_N();
		if (id <200)
		{
			Serial.print("Verified ID:");
			Serial.println(id);
		}
		else
		{
			Serial.println("Finger not found");
		}
	}
	else
	{
		Serial.println("Please press finger");
	}
	delay(100);
}
