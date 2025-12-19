/*
 * InputDriver.cpp
 *
 *  Created on: Nov 25, 2025
 *      Author: Logan
 */

#include "InputDriver.h"


InputDriver::InputDriver(queue* Sem, queue* qI)
{
	Semaphore = Sem;
	qInputs = qI;

	devices.Button = 0;
	devices.Switch = 0;

	prevDevices.Button = 0;
	prevDevices.Switch = 0;
}

void InputDriver::Update()
{
	void* data_ptr;
//	if (Semaphore->dequeue(&data_ptr) == false)
//		return;
	uint8_t inc = 0;
	uint8_t dec = 0;

	inc = macro.Update(PA, 4);
	dec = macro.Update(PB, 1);

	if (inc == 1 && dec == 0)
		devices.Button = 1;
	else if (inc == 0 && dec == 1)
		devices.Button = -1;
	else
		devices.Button = 0;

	devices.Switch = state.Update();

	if ((devices.Button != prevDevices.Button) || (devices.Switch != prevDevices.Switch))
	{
		prevDevices.Button = devices.Button;
		prevDevices.Switch = devices.Switch;

		qInputs->enqueue((void*)&devices);
	}
	return;
}
