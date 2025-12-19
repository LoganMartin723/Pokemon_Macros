/*
 * ButtonDriver.cpp
 *
 *  Created on: Nov 25, 2025
 *      Author: Logan
 */

#include "ButtonDriver.h"


Button::Button() {}

uint8_t Button::Update(GPIO_TypeDef * port, uint8_t pin)
{
	uint8_t pressed = 0;

	if (READ(port,pin) == 0)
		pressed = 1;
	else
		pressed = 0;

	return pressed;
}
