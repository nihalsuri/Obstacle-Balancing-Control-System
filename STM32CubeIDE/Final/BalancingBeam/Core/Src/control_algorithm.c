/**
  ******************************************************************************
  * @file    control_algorithm.c
  * @authors  NS        Nihal.Suri@student.put.poznan.pl     MM          Maciej.Mirecki@student.put.poznan.pl
  * @version 2.0
  * @date    28-12-2021
  * @brief   PID control algorithm for balancing beam.
  *
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "control_algorithm.h"

/* Typedef -------------------------------------------------------------------*/

/* Define --------------------------------------------------------------------*/

/* Macro ---------------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private function ----------------------------------------------------------*/

/* Public function -----------------------------------------------------------*/


/**
 * @brief PID controller implementation.
 * @note calculation of duty cycle fed to servo
 * @param[in] dist :  current distance of obstacle
 * @param[in] setp :  set point
 * @return duty cycle [% * 10]
 */
int pid_control(float dist, int setp){

		error = (float32_t)(setp-dist);

		SWV_VAR = arm_pid_f32(&pid, error);

		duty_val = LINEAR_TRANSFORM(SWV_VAR, ANGLE_MIN, ANGLE_MAX, DUTY_MIN, DUTY_MAX);

		if(duty_val <= DUTY_MIN){
			duty_val = DUTY_MIN;
		}
		else if(duty_val >= DUTY_MAX){
			duty_val = DUTY_MAX;
		}
		if(dist < setp + setp*0.01 && dist > setp- setp*0.01 ){
			duty_val=HOME_POS;
		}
		return duty_val;
	}
