/*
 * StateDriver.h
 *
 *  Created on: Nov 8, 2025
 *      Author: Logan
 */

#ifndef REPO_INC_STATEDRIVER_H_
#define REPO_INC_STATEDRIVER_H_

#pragma once

#include "main.h"
#include "stdint.h"
#include "cpp_main.h"
#include "GPIO_Pins.h"
#include "queue.h"

class StateDriver
{
	queue* qInputs;
	queue* qStateDisplay;
	InputDevices Devices;
	StateChange State;
public:
	StateDriver(queue*, queue*);
	void Update();
};


#endif /* REPO_INC_STATEDRIVER_H_ */
