/*
 * Macros.cpp
 *
 *  Created on: Nov 8, 2025
 *      Author: Logan
 */

#include "Macros.h"



extern USB_JoystickReport_Input joystick_input;

Macros::Macros(queue* qMS)
{
	qMacroState = qMS;
	State.CurrentMacro = ZONE1;
	State.CurrentState = START;
}

void Macros::USB_Busy()
{
	USBD_HID_HandleTypeDef *hhid = (USBD_HID_HandleTypeDef*)hUsbDeviceFS.pClassData;
	for (uint32_t i = 0; i < 0xffffffff; i++)
	{
		if (hhid->state != 1) //1 indicates that the USB bus is busy transmitting data
			break;
	}
	return;
}

void Macros::Update()
{
	void* data_ptr;
	StateChange* value_ptr;

	if (qMacroState->dequeue(&data_ptr) == false)
		return;

	value_ptr = (StateChange*)data_ptr;
	State = *value_ptr;


	if (State.CurrentState == RUNNING)
	{
		switch (State.CurrentMacro)
		{
			case ZONE1:
			{
				wild_zone_1();
				break;
			}

			case ZONE2:
			{
				wild_zone_2();
				break;
			}

			case ZONE3:
			{
				wild_zone_3();
				break;
			}

			case ZONE4:
			{
				wild_zone_4();
				break;
			}

			case ZONE5:
			{
				wild_zone_5();
				break;
			}

			case ZONE6:
			{
				wild_zone_6();
				break;
			}

			case ZONE7:
			{
				wild_zone_7();
				break;
			}

			case ZONE8:
			{
				wild_zone_8();
				break;
			}

			case ZONE9:
			{
				wild_zone_9();
				break;
			}

			case ZONE10:
			{
				wild_zone_10();
				break;
			}

			case ZONE11:
			{
				wild_zone_11();
				break;
			}

			case ZONE12:
			{
				wild_zone_12();
				break;
			}

			case ZONE13:
			{
				wild_zone_13();
				break;
			}

			case ZONE14:
			{
				wild_zone_14();
				break;
			}

			case ZONE15:
			{
				wild_zone_15();
				break;
			}

			case ZONE16:
			{
				wild_zone_16();
				break;
			}

			case ZONE17:
			{
				wild_zone_17();
				break;
			}

			case ZONE18:
			{
				wild_zone_18();
				break;
			}

			case ZONE19:
			{
				wild_zone_19();
				break;
			}

			case ZONE20:
			{
				wild_zone_20();
				break;
			}

			case BENCHRESET:
			{
				bench_reset();
				break;
			}

			case AUTOBATTE:
			{
				auto_battle();
				break;
			}

			case TURBOA:
			{
				turbo_a();
				break;
			}

			default:
			{
				break;
			}
		}
	}
	else
	{
		ResetReport(&hUsbDeviceFS, &joystick_input);
	}
//	USB_Busy();
	qMacroState->enqueue((void*)&State);
	return;
}



void Macros::wild_zone_1()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LX = STICK_MIN;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);

	return;
}

void Macros::wild_zone_2()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LY = STICK_MIN;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_3()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LY = STICK_MIN;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_4()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LX = STICK_MAX;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_5()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LY = STICK_MIN;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_6()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LY = STICK_MIN;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_7()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LX = STICK_MIN;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_8()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LX = STICK_MIN;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_9()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LY = STICK_MIN;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_10()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LX = STICK_MAX;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_11()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LX = STICK_MIN;
	joystick_input.LY = 117;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_12()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LY = STICK_MIN;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_13()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LX = STICK_MIN;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_14()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LY = STICK_MAX;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_15()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LX = STICK_MIN;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_16()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LY = STICK_MIN;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_17()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LY = STICK_MIN;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_18()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LY = STICK_MAX;
	joystick_input.LX = 117;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_19()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LY = STICK_MAX;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::wild_zone_20()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms

	joystick_input.Button = SWITCH_PLUS;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	HAL_Delay(1000); // in ms

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.LX = STICK_MIN;
	HoldReport(&hUsbDeviceFS, &joystick_input,150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms


	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(1000); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(750); // in ms

	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(3750);
	return;
}

void Macros::bench_reset()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms


	joystick_input.LY = STICK_MAX;
	HoldReport(&hUsbDeviceFS, &joystick_input,250);

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(500); // in ms

	for (uint8_t i = 0; i < 6; i++)
	{
		joystick_input.Button = SWITCH_A;
		HoldReport(&hUsbDeviceFS, &joystick_input, 150);

		ResetReport(&hUsbDeviceFS, &joystick_input);
		HAL_Delay(1000); // in ms
	}

	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(14000);
	return;
}

void Macros::auto_battle()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms
	joystick_input.Button = SWITCH_ZL;
	HoldReport(&hUsbDeviceFS, &joystick_input, 300);
	joystick_input.Button |= SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 300);

	return;
}


void Macros::turbo_a()
{
	ResetReport(&hUsbDeviceFS, &joystick_input);
	HAL_Delay(100); // in ms
	joystick_input.Button = SWITCH_A;
	HoldReport(&hUsbDeviceFS, &joystick_input, 150);
	return;
}
