/*
 * GPIO_Pins.h
 *
 *  Created on: May 17, 2025
 *      Author: logan
 */

#ifndef REPO_INC_GPIO_PINS_H_
#define REPO_INC_GPIO_PINS_H_

#include "stdint.h"
#include "main.h"

//GPIO Ports
#define PA (GPIO_TypeDef *)GPIOA
#define PB (GPIO_TypeDef *)GPIOB
#define PC (GPIO_TypeDef *)GPIOC
#define PD (GPIO_TypeDef *)GPIOD


//GPIO Functions
#define SET(port,pin) ((port)->ODR |= (1 << (pin)))
#define CLEAR(port,pin) ((port)->ODR &= ~(1 << (pin)))
#define TOGGLE(port,pin) ((port)->ODR ^= (1 << (pin)))
#define READ(port,pin) (((port)->IDR & (1 << (pin)))) // Input Read = 0, No Input Read = 1




#endif /* REPO_INC_GPIO_PINS_H_ */
