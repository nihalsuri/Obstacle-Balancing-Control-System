/**
  ******************************************************************************
  * @file    led_routine.c
  * @authors  NS        Nihal.Suri@student.put.poznan.pl     MM          Maciej.Mirecki@student.put.poznan.pl
  * @version 2.0
  * @date    28-12-2021
  * @brief   PID control algorithm for balancing beam.
  *
  ******************************************************************************
  */
  /* Config --------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
#include <ui.h>

/* Define ---------------------------------------------------------------------*/

/* Macro ---------------------------------------------------------------------*/


/* Public variables ----------------------------------------------------------*/


/* Public function prototypes ------------------------------------------------*/


/**
 * @brief LED control
 * @note green (<0.1% error) blue (0.3 - 0.5% error) red (>0.5% error)
 * @param[in] none
 * @return None
 */

void led_routine(){

	  if(fabs(error) <= 0.3){
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);
		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 0);
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, 1);
	 	  }

	  else if( fabs(error) > 0.31 && fabs(error) < 0.6){
	  		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);
	  		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 1);
	  		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, 0);
	  	}
	  else	  if( fabs(error) > 0.6){
	  		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
	  		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, 0);
	  		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, 0);
	  	}
}

/**
 * @brief Triggered by USER_Btn, for calibration only
 * @note Sets angle of beam to 0 degrees
 * @param[in] none
 * @return None
 */
void reset_beam_position(TIM_HandleTypeDef *htim2, TIM_HandleTypeDef *htim3){
	HAL_TIM_Base_Stop_IT(htim3);
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	__HAL_TIM_SET_COMPARE(htim2, TIM_CHANNEL_1, 73);
}

/**
 * @brief Prints data on LCD display
 * @note
 * @param[in] none
 * @return None
 */
void lcd_routine(LCD_HandleTypeDef* hlcd1){
	  sprintf(pos_dist, "%.02f", d);
	  sprintf(duty_print, "%lu", duty_val);
	  sprintf(sp_str, "%d", sp);
	  LCD_SetCursor(hlcd1, 0, 0);
	  LCD_printStr(hlcd1, "DISTANCE: ");
	  LCD_printStr(hlcd1, pos_dist);
	  //LCD_printStr(hlcd1, "cm");
	  LCD_SetCursor(hlcd1, 1, 0);
	  LCD_printStr(hlcd1, "SETPOINT: ");
	  LCD_printStr(hlcd1, sp_str);

}

int ADC_SETPOINT(ADC_HandleTypeDef* hadc){

	if(hadc->Instance == ADC1){

	 HAL_ADC_Start(&hadc1);

	 if(HAL_ADC_PollForConversion(&hadc1, 500) == HAL_OK){
			sample_in = HAL_ADC_GetValue(&hadc1);
	  }
	}

	return abs((sample_in/100) - 20)+10;
}
