/**
  ******************************************************************************
  * @file    uart_tx.h
  * @authors  NS        Nihal.Suri@student.put.poznan.pl     MM          Maciej.Mirecki@student.put.poznan.pl
  * @version 2.0
  * @date    28-12-2021
  * @brief   PID control algorithm for balancing beam.
  *
  ******************************************************************************
  */
  /* Config --------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include <arm_math.h>
#include <stdio.h>
#include<string.h>
#include <stdint.h>
/* Define ---------------------------------------------------------------------*/

/* Macro ---------------------------------------------------------------------*/

/* Private variables ----------------------------------------------------------*/
char msg[50];

/* Public variables ----------------------------------------------------------*/
int sp;
float d;
/* Public function prototypes ------------------------------------------------*/


/**
 * @brief Transmitting data through UART to dedicated app.
 * @param[in] time :  time in microseconds
 * @param[in] htim8 :  Input Capture timer handler
 * @return None
 */
void uart_tx(UART_HandleTypeDef *huart3);

