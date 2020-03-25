/*
 * Program to configure a RFD900 from an arduino
 * 
 * Author:
 * 		Maxime Guillemette
 * 
 * Date:
 * 		2020-03-25
 */


/* includes */
#include "Arduino.h"


/* definitions */
#define BAUD_USB 9600
#define BAUD_RFD 9600


void setup(void) {
	/* init USB serial port */
	Serial.begin(BAUD_USB);

	/* init pins serial port to RFD900 */
	Serial2.begin(BAUD_RFD);

  Serial.println("start");
  Serial2.print("+++");
}


void loop(void) {
//	if (Serial.available()) {
//		Serial.write(Serial.read());
//	}
	/* transfer from USB to RFD */
	if (Serial.available()) {
		Serial2.write(Serial.read());
	}

	/* transfer from RFD to USB */
	if (Serial2.available()) {
		Serial.write(Serial2.read());
	}
}
