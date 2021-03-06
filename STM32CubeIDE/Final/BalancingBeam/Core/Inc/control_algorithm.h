/**
  ******************************************************************************
  * @file    control_algorithm.h
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

/* Define ---------------------------------------------------------------------*/
#define LINEAR_TRANSFORM(x,amin,amax,bmin,bmax) (((x-amin)/(amax-amin))*(bmax-bmin)+bmin)
#define DUTY_MAX 87
#define DUTY_MIN 55
#define ANGLE_MAX 7.5
#define ANGLE_MIN -6.9
#define HOME_POS 73
/* Macro ---------------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/
uint32_t duty_val = 0;
float32_t SWV_VAR = 0.0f;
float32_t error = 0.0f;
float d = 0.0f;
int sp=10;
arm_pid_instance_f32 pid = {.Kp = 1, .Ki = 0.000147368, .Kd =0.35};

/* Public function prototypes ------------------------------------------------*/


/**
 * @brief PID controller implementation.
 * @note calculation of duty cycle fed to servo
 * @param[in] dist :  current distance of obstacle
 * @param[in] setp :  set point
 * @return duty cycle [% * 10]
 */
int pid_control(float dist, int setp);

