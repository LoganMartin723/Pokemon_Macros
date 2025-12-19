/*
 * cpp_main.h
 *
 *  Created on: May 17, 2025
 *      Author: logan
 */

#ifndef REPO_INC_CPP_MAIN_H_
#define REPO_INC_CPP_MAIN_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

#include "internal_peripheral_control.h"

typedef struct
{
	uint8_t Switch;
	int8_t Button;
}InputDevices;

typedef enum
{
	START,
	RUNNING
}MacroState;

typedef enum
{
	ZONE1,
	ZONE2,
	ZONE3,
	ZONE4,
	ZONE5,
	ZONE6,
	ZONE7,
	ZONE8,
	ZONE9,
	ZONE10,
	ZONE11,
	ZONE12,
	ZONE13,
	ZONE14,
	ZONE15,
	ZONE16,
	ZONE17,
	ZONE18,
	ZONE19,
	ZONE20,
	BENCHRESET,
	AUTOBATTE,
	TURBOA
}Macro;

typedef struct
{
	MacroState CurrentState;
	Macro CurrentMacro;
}StateChange;

void cpp_main(void);

#ifdef __cplusplus
}
#endif

#endif /* REPO_INC_CPP_MAIN_H_ */
