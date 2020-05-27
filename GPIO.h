/*
 *
 * nRF52 GPIO Library
 * Ver 1.0
 * May 22, 2020
 * Roverdyn Inc.
 * jswcomkr@roverdyn.com
 *
 */

#include <stdio.h>
#include <nrf_gpio.h>

#ifndef GPIO_H_
#define GPIO_H_

#define OUTPUT 1
#define INPUT 0
#define LOW 0
#define HIGH 1

class _GPIO{
public:
	void pinMode(uint8_t pinNo, bool isMode);
	void digitalWrite(uint8_t pinNo, bool toggle);
	bool digitalRead(uint8_t pinNo);
};



#endif /* GPIO_H_ */
