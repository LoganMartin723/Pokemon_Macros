/*
 * InputDriver.h
 *
 *  Created on: Nov 25, 2025
 *      Author: Logan
 */

#ifndef INC_INPUTDRIVER_H_
#define INC_INPUTDRIVER_H_

#pragma once

#include "main.h"
#include "stdint.h"

#include "cpp_main.h"
#include "GPIO_Pins.h"
#include "queue.h"

#include "ButtonDriver.h"
#include "SwitchDriver.h"

class InputDriver
{
	Button macro;
	Switch state;

	queue* qInputs;
	queue* Semaphore;

	InputDevices devices;
	InputDevices prevDevices;

public:
	InputDriver(queue*, queue*);
	void Update();
};



#endif /* INC_INPUTDRIVER_H_ */
