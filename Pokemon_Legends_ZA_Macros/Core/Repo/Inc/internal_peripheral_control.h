/*
 * peripheral_control.h
 *
 *  Created on: Jul 30, 2025
 *      Author: lmartin
 */

#ifndef REPO_INC_INTERNAL_PERIPHERAL_CONTROL_H_
#define REPO_INC_INTERNAL_PERIPHERAL_CONTROL_H_

//In CR1 {Control Register 1} for timer
#define CEN 0

//In CCER {Compare/Capture Enable Register} for timer
#define CC1E 0  //Compare register CCR1
#define CC2E 4  //Compare register CCR2
#define CC3E 8  //Compare register CCR3
#define CC4E 12 //Compare register CCR4


#define ENABLE_PWM(timer, channel) {\
		(timer)->CR1 |= (1 << CEN);\
		(timer)->CCER |= (1 << channel);\
}


#define TIM_CLK 84000000
#define TIM4_PSC 84

#define CEN 0

#define START_TIMER(timer)  (timer->CR1 |= (1 << CEN))
#define STOP_TIMER(timer)  (timer->CR1 &= ~(1 << CEN))

#endif /* REPO_INC_INTERNAL_PERIPHERAL_CONTROL_H_ */
