/*
 *
 * nRF52 GPIO Library
 * Ver 1.0
 * May 22, 2020
 * Roverdyn Inc.
 * jswcomkr@roverdyn.com
 *
 */

#include "GPIO.h"

void _GPIO::pinMode(uint8_t pinNo, bool isMode){
	if(isMode){
		// Output
		NRF_GPIO->DIRSET = 1 << (uint32_t)pinNo;
	}else{
		// Input
		NRF_GPIO->PIN_CNF[pinNo] = 0x0C;
	}
}

void _GPIO::digitalWrite(uint8_t pinNo, bool toggle){
	if(toggle){
		NRF_GPIO->OUTSET = 1 << (uint32_t)pinNo;
	}else{
		NRF_GPIO->OUTCLR = 1 << (uint32_t)pinNo;
	}

}

bool _GPIO::digitalRead(uint8_t pinNo){
	bool output = (NRF_GPIO->IN >> pinNo) & 0x01;
	return output;
}
