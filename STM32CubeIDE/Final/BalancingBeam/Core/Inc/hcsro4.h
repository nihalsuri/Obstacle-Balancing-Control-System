/**
  ******************************************************************************
  * @file    hcsro4.h
  * @authors  NS        Nihal.Suri@student.put.poznan.pl     MM          Maciej.Mirecki@student.put.poznan.pl
  * @version 2.0
  * @date    28-12-2021
  * @brief   Driver for ultrasonic distance sensor with Timer Input Capture Mode: HCSRO4.
  *
  ******************************************************************************
  */

#ifndef INC_HCSRO4_H_
#define INC_HCSRO4_H_

/* Config --------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/* Define --------------------------------------------------------------------*/
#define TRIG_PIN GPIO_PIN_7
#define TRIG_PORT GPIOC


/* Macro ---------------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

uint32_t IC_Val1 = 0;
uint32_t IC_Val2 = 0;
uint32_t Difference = 0;
uint8_t Is_First_Captured = 0;  // is the first value captured ?
float Distance  = 0;

/* Public function prototypes ------------------------------------------------*/


/**
 * @brief delay procedure.
 * @note delay between transmitting and receiving pulses
 * @param[in] time :  time in microseconds
 * @param[in] htim8 :  Input Capture timer handler
 * @return None
 */

void delay_us(uint16_t time, TIM_HandleTypeDef *htim8);

/**
 * @brief Input Capture Timer Callback.
 * @note Calculates distance by difference in time between pulses
 * @param[in] htim8 :  Input Capture timer handler
 * @return None
 */

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim8);

/**
 * @brief Reads sensor values
 * @note Changes state of TRIG pin and enables interrupt for timer
 * @param[in] htim8 :  Input Capture timer handler
 * @return None
 */

void HCSRO4_Read (TIM_HandleTypeDef *htim8);




#endif /* INC_HCSRO4_H_ */
