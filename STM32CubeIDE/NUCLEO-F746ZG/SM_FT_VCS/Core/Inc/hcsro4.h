/*
 * hcsro4.h
 *
 *  Created on: Dec 27, 2021
 *      Author: Nihal Suri
 */

#ifndef INC_HCSRO4_H_
#define INC_HCSRO4_H_

#include "stm32f7xx_hal.h"


uint32_t IC_Val1 = 0;
uint32_t IC_Val2 = 0;
uint32_t Difference = 0;
uint8_t Is_First_Captured = 0;  // is the first value captured ?
uint8_t Distance  = 0;


#define TRIG_PIN GPIO_PIN_7
#define TRIG_PORT GPIOC


void delay_us(uint16_t time, TIM_HandleTypeDef *htim8);
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim8);
void HCSRO4_Read (TIM_HandleTypeDef *htim8);




#endif /* INC_HCSRO4_H_ */
