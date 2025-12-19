/*
 * cpp_main.cpp
 *
 *  Created on: May 17, 2025
 *      Author: logan
 */

#include "stdint.h"
#include "main.h"
#include "stm32l4xx_hal_tim.h"

#include "cpp_main.h"
#include "GPIO_Pins.h"
#include "queue.h"
#include "SSD1306_SPI_Driver.h"
#include "StateDriver.h"
#include "InputDriver.h"
#include "ns_joystick.h"
#include "Macros.h"


extern "C" void cpp_main();


#define COMMAND_SYNC_START          (0x80)
#define RESP_SYNC_START             (0xFF)
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)


extern USB_JoystickReport_Input joystick_input;
uint8_t rx_buf = 0x00;
uint8_t serial_buf[8];
uint8_t serial_idx = 0;

static queue Semaphore;
extern TIM_HandleTypeDef htim7;

extern "C" void xSemaphoreCheck_IRQHandler(void)
{
	if (__HAL_TIM_GET_FLAG(&htim7, TIM_FLAG_UPDATE))
	{
		if (__HAL_TIM_GET_IT_SOURCE(&htim7, TIM_IT_UPDATE))
		{
			__HAL_TIM_CLEAR_IT(&htim7, TIM_IT_UPDATE);
			Semaphore.enqueue((void*)1);
		}
	}
}

void cpp_main()
{
	ResetReport(&hUsbDeviceFS,&joystick_input);

	queue qInputs;
	queue qMacro;
	queue qDisplay;

	InputDriver inputs = InputDriver(&Semaphore, &qInputs);
	StateDriver state = StateDriver(&qInputs, &qDisplay);
	OLED display = OLED(&qDisplay,&qMacro);
	Macros macro = Macros(&qMacro);

	// This is just to initially connect the emulator to the system.
	ResetReport(&hUsbDeviceFS, &joystick_input);

	while(1)
	{
		ResetReport(&hUsbDeviceFS, &joystick_input);
		inputs.Update();
		state.Update();
		display.Update();
		macro.Update();
	}
	return;
}


