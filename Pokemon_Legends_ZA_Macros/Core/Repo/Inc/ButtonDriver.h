/*
 * ButtonDriver.h
 *
 *  Created on: Nov 25, 2025
 *      Author: Logan
 */

#ifndef REPO_INC_BUTTONDRIVER_H_
#define REPO_INC_BUTTONDRIVER_H_

#pragma once

#include "cpp_main.h"
#include "GPIO_Pins.h"
#include "queue.h"
#include "stdint.h"


class Button
{
public:
	Button();
	uint8_t Update(GPIO_TypeDef *, uint8_t);
};





#endif /* REPO_INC_BUTTONDRIVER_H_ */
