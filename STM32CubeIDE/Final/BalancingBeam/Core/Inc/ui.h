/**
  ******************************************************************************
  * @file    ui.h
  * @authors  NS        Nihal.Suri@student.put.poznan.pl     MM          Maciej.Mirecki@student.put.poznan.pl
  * @version 2.0
  * @date    28-12-2021
  * @brief   User Interface: led control, lcd control, ADC input.
  *
  ******************************************************************************
  */
  /* Config --------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include <math.h>
#include <arm_math.h>
#include <lcd.h>
#include <adc.h>
/* Define ---------------------------------------------------------------------*/

/* Macro ---------------------------------------------------------------------*/

/* Private variables ----------------------------------------------------------*/

char duty_print[10];
char pos_dist[10];
char sp_str[];
uint32_t sample_in;
/* Public variables ----------------------------------------------------------*/
float32_t error;
float d;
uint32_t duty_val;
int sp;
/* Public function prototypes ------------------------------------------------*/


/**
 * @brief LED control
 * @note green (<0.1% error) blue (0.3 - 0.5% error) red (>0.5% error)
 * @param[in] none
 * @return None
 */
void led_routine();

/**
 * @brief Triggered by USER_Btn, for calibration purpose only
 * @note Sets angle of servo to 0 degrees - default position
 * @param[in] htim2 : timer handler for servo
 * @param[in] htim3 : timer handler for PID control algorithm
 * @return None
 */
void reset_beam_position(TIM_HandleTypeDef *htim2, TIM_HandleTypeDef *htim3);

/**
/**
 * @brief Prints data on LCD display
 * @note printing real-time position and current setpoint
 * @param[in] hlcd1 : lcd handler
 * @return None
 */
void lcd_routine(LCD_HandleTypeDef* hlcd1);


/**
 * @brief Reading ADC register value
 * @note reading ADC register value and converting it into setpoint value
 * @param[in] hadc : adc handler
 * @return setpoint value in [cm]
 */
int ADC_SETPOINT(ADC_HandleTypeDef* hadc);
