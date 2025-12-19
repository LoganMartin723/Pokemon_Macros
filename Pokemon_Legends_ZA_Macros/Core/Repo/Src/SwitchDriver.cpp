/*
 * SwitchDriver.cpp
 *
 *  Created on: Nov 25, 2025
 *      Author: Logan
 */


#include "SwitchDriver.h"

Switch::Switch() {}

uint8_t Switch::Update()
{
	uint8_t state = OFF;

	if (READ(PA,5) == 0)
		state = ON;
	else
		state = OFF;
	return state;
}
