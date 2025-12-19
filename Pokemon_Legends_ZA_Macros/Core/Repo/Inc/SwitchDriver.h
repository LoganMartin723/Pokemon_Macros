/*
 * SwitchDriver.h
 *
 *  Created on: Nov 25, 2025
 *      Author: Logan
 */

#ifndef REPO_INC_SWITCHDRIVER_H_
#define REPO_INC_SWITCHDRIVER_H_

#pragma once

#include "cpp_main.h"
#include "GPIO_Pins.h"
#include "queue.h"
#include "stdint.h"

#define ON 1
#define OFF 0

class Switch
{
public:
	Switch();
	uint8_t Update();
};


#endif /* REPO_INC_SWITCHDRIVER_H_ */
