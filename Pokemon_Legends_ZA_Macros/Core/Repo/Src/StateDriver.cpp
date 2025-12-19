/*
 * StateDriver.cpp
 *
 *  Created on: Nov 8, 2025
 *      Author: Logan
 */


#include "StateDriver.h"

StateDriver::StateDriver(queue*	qI,queue* qD)
{
	qInputs = qI;
	qStateDisplay = qD;
	State.CurrentMacro = ZONE1;
	State.CurrentState = START;
}

void StateDriver::Update()
{

	void* data_ptr;
	InputDevices* values;
	if (qInputs->dequeue(&data_ptr) == false)
		return;

	values = (InputDevices*)data_ptr;
	Devices.Button = values->Button;
	Devices.Switch = values->Switch;


	if (Devices.Button == 1 && State.CurrentState != RUNNING)
	{
		switch(State.CurrentMacro)
		{
		case ZONE1:
		{
			State.CurrentMacro = ZONE2;
			break;
		}

		case ZONE2:
		{
			State.CurrentMacro = ZONE3;
			break;
		}

		case ZONE3:
		{
			State.CurrentMacro = ZONE4;
			break;
		}

		case ZONE4:
		{
			State.CurrentMacro = ZONE5;
			break;
		}

		case ZONE5:
		{
			State.CurrentMacro = ZONE6;
			break;
		}

		case ZONE6:
		{
			State.CurrentMacro = ZONE7;
			break;
		}

		case ZONE7:
		{
			State.CurrentMacro = ZONE8;
			break;
		}

		case ZONE8:
		{
			State.CurrentMacro = ZONE9;
			break;
		}

		case ZONE9:
		{
			State.CurrentMacro = ZONE10;
			break;
		}

		case ZONE10:
		{
			State.CurrentMacro = ZONE11;
			break;
		}

		case ZONE11:
		{
			State.CurrentMacro = ZONE12;
			break;
		}

		case ZONE12:
		{
			State.CurrentMacro = ZONE13;
			break;
		}

		case ZONE13:
		{
			State.CurrentMacro = ZONE14;
			break;
		}

		case ZONE14:
		{
			State.CurrentMacro = ZONE15;
			break;
		}

		case ZONE15:
		{
			State.CurrentMacro = ZONE16;
			break;
		}

		case ZONE16:
		{
			State.CurrentMacro = ZONE17;
			break;
		}

		case ZONE17:
		{
			State.CurrentMacro = ZONE18;
			break;
		}

		case ZONE18:
		{
			State.CurrentMacro = ZONE19;
			break;
		}

		case ZONE19:
		{
			State.CurrentMacro = ZONE20;
			break;
		}

		case ZONE20:
		{
			State.CurrentMacro = BENCHRESET;
			break;
		}

		case BENCHRESET:
		{
			State.CurrentMacro = AUTOBATTE;
			break;
		}

		case AUTOBATTE:
		{
			State.CurrentMacro = TURBOA;
			break;
		}

		case TURBOA:
		{
			State.CurrentMacro = ZONE1;
			break;
		}

			default:
			{
				break;
			}
		}
	}

	else if (Devices.Button == -1 && State.CurrentState != RUNNING)
	{
		switch(State.CurrentMacro)
		{
		case ZONE1:
		{
			State.CurrentMacro = TURBOA;
			break;
		}

		case ZONE2:
		{
			State.CurrentMacro = ZONE1;
			break;
		}

		case ZONE3:
		{
			State.CurrentMacro = ZONE2;
			break;
		}

		case ZONE4:
		{
			State.CurrentMacro = ZONE3;
			break;
		}

		case ZONE5:
		{
			State.CurrentMacro = ZONE4;
			break;
		}

		case ZONE6:
		{
			State.CurrentMacro = ZONE5;
			break;
		}

		case ZONE7:
		{
			State.CurrentMacro = ZONE6;
			break;
		}

		case ZONE8:
		{
			State.CurrentMacro = ZONE7;
			break;
		}

		case ZONE9:
		{
			State.CurrentMacro = ZONE8;
			break;
		}

		case ZONE10:
		{
			State.CurrentMacro = ZONE9;
			break;
		}

		case ZONE11:
		{
			State.CurrentMacro = ZONE10;
			break;
		}

		case ZONE12:
		{
			State.CurrentMacro = ZONE11;
			break;
		}

		case ZONE13:
		{
			State.CurrentMacro = ZONE12;
			break;
		}

		case ZONE14:
		{
			State.CurrentMacro = ZONE13;
			break;
		}

		case ZONE15:
		{
			State.CurrentMacro = ZONE14;
			break;
		}

		case ZONE16:
		{
			State.CurrentMacro = ZONE15;
			break;
		}

		case ZONE17:
		{
			State.CurrentMacro = ZONE16;
			break;
		}

		case ZONE18:
		{
			State.CurrentMacro = ZONE17;
			break;
		}

		case ZONE19:
		{
			State.CurrentMacro = ZONE18;
			break;
		}

		case ZONE20:
		{
			State.CurrentMacro = ZONE19;
			break;
		}

		case BENCHRESET:
		{
			State.CurrentMacro = ZONE20;
			break;
		}

		case AUTOBATTE:
		{
			State.CurrentMacro = BENCHRESET;
			break;
		}

		case TURBOA:
		{
			State.CurrentMacro = AUTOBATTE;
			break;
		}

			default:
			{
				break;
			}
		}
	}

	if (Devices.Switch == 1)
		State.CurrentState = RUNNING;

	else if (Devices.Switch == 0)
		State.CurrentState = START;


	qStateDisplay->enqueue((void*)&State);

	return;
}
