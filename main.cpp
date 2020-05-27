/*
 * nRF52 GPIO Library Example
 *
 * May 22, 2020
 * Roverdyn Inc.
 * jswcomkr@roverdyn.com
 *
 */

#include "GPIO.h"
#include <nrf_delay.h>

#define BUTTON 22
#define LED0 25
#define LED1 26

static _GPIO GPIO;

int main(void){
	// Set GPIO pin
	// Set button pin as input
	GPIO.pinMode(BUTTON, INPUT);

	// Set LED pins as output
	GPIO.pinMode(LED0, OUTPUT);
	GPIO.pinMode(LED1, OUTPUT);

	// Turn on LED
	GPIO.digitalWrite(LED0, LOW);
	GPIO.digitalWrite(LED1, LOW);

	// Delay
	nrf_delay_ms(2000);

	// Turn off LED
	GPIO.digitalWrite(LED0, HIGH);
	GPIO.digitalWrite(LED1, HIGH);

	// Start loop
	while(1){
		// Read button input
		bool isBtn = GPIO.digitalRead(BUTTON);

		if(!isBtn){
			// Turn on LED1
			GPIO.digitalWrite(LED0, LOW);

			// Turn off LED0
			GPIO.digitalWrite(LED1, LOW);
		}else{
			// Turn on LED1
			GPIO.digitalWrite(LED0, HIGH);

			// Turn off LED0
			GPIO.digitalWrite(LED1, HIGH);
		}
	}

	return 0;
}
