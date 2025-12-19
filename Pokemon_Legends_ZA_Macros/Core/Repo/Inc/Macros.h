/*
 * Macros.h
 *
 *  Created on: Nov 8, 2025
 *      Author: Logan
 */

#ifndef REPO_INC_MACROS_H_
#define REPO_INC_MACROS_H_

#include "cpp_main.h"
#include "queue.h"
#include "ns_joystick.h"

#pragma once



class Macros
{
	queue* qMacroState;
	StateChange State;

public:
	Macros(queue*);
	void Update();
	void USB_Busy();
	void wild_zone_1();
	void wild_zone_2();
	void wild_zone_3();
	void wild_zone_4();
	void wild_zone_5();
	void wild_zone_6();
	void wild_zone_7();
	void wild_zone_8();
	void wild_zone_9();
	void wild_zone_10();
	void wild_zone_11();
	void wild_zone_12();
	void wild_zone_13();
	void wild_zone_14();
	void wild_zone_15();
	void wild_zone_16();
	void wild_zone_17();
	void wild_zone_18();
	void wild_zone_19();
	void wild_zone_20();
	void bench_reset();
	void auto_battle();
	void turbo_a();
};





#endif /* REPO_INC_MACROS_H_ */
