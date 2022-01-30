/**
  ******************************************************************************
  * @file    uart_tx.c
  * @authors  NS        Nihal.Suri@student.put.poznan.pl     MM          Maciej.Mirecki@student.put.poznan.pl
  * @version 2.0
  * @date    28-12-2021
  * @brief   UART communication with dedicated desktop application.
  *
  ******************************************************************************
  */
  /* Config --------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
#include <uart_tx.h>

/* Define ---------------------------------------------------------------------*/

/* Macro ---------------------------------------------------------------------*/


/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/


/**
 * @brief Transmitting data through UART to dedicated app.
 * @param[in] huart3 : UART3 handler
 * @return None
 */
void uart_tx(UART_HandleTypeDef *huart3){
	if(d >= 10.0){
		 int n = sprintf(msg, "%.02f, %d", d, sp);
		 HAL_UART_Transmit_IT(huart3, (uint8_t*)msg,n);

		}
		else{
			 int n = sprintf(msg, "0%.02f, %d", d, sp);
			 HAL_UART_Transmit_IT(huart3, (uint8_t*)msg,n);

		}
}

