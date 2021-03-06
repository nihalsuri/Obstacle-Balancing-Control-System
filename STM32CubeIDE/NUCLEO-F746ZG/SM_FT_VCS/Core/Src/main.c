/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "arm_math.h"
#include "lcd_config.h"
#include "string.h"
#include "stdio.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define LINEAR_TRANSFORM(x,amin,amax,bmin,bmax) (((x-amin)/(amax-amin))*(bmax-bmin)+bmin) // angle to duty transform

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

float d = 0;
extern float Distance;

char dist[] = "POSITION :";
char setpoint[] = "SETPOINT : ";
char duty_LCD[] = "DUTY: ";
char cm[] = " cm";
int HomePosition = 73;

char pos_dist[10];
char set[10];
char duty_print[10];

int Kp=1.0, Ki=0.0;
float32_t kkp = 1.0;
float32_t kki = 0;

int duty=73; //only for calibration
char msg[]={}; //only for calibration
char msg1[]={};

uint32_t SETPOINT = 14;
uint32_t duty_val = 0;
float32_t SWV_VAR = 0;
float32_t error = 0;

arm_pid_instance_f32 pid = {.Kp = 1.3, .Ki = 0.001, .Kd =0.0001};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

// PID Control Algorithm

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim){
	if(htim->Instance == TIM3){

		error = (float32_t)(SETPOINT-d);
		SWV_VAR = arm_pid_f32(&pid, error);
		duty_val = LINEAR_TRANSFORM(SWV_VAR, -6.9, 7.5, 55, 87); // angle and duty of servo relation

		if(duty_val <= 55){
			duty_val = 55; // max angle
		}
		else if(duty_val >= 87){
			duty_val = 87; // minimum angle
		}

		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, (int)duty_val); // set counter value

	}
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_TIM2_Init();
  MX_I2C1_Init();
  MX_USART3_UART_Init();
  MX_GPIO_Init();
  MX_SPI4_Init();
  MX_DMA_Init();
  MX_TIM8_Init();
  MX_ADC1_Init();
  MX_TIM5_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */

  HAL_TIM_IC_Start_IT(&htim8, TIM_CHANNEL_1); // captures pulses
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); // servo control
  HAL_TIM_Base_Start_IT(&htim3); // PID Control Callback 100ms sampling
  LCD_Init(&hlcd1); // initialize LCD

  arm_pid_init_f32(&pid,1);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  //Sensor
	  HCSRO4_Read(&htim8);
	  HAL_Delay(30);
	  d = Distance;


	  //LCD
	  sprintf(pos_dist, "%.02f", d);
	  sprintf(duty_print, "%d", duty_val);

	  LCD_SetCursor(&hlcd1, 0, 0);
	  LCD_printStr(&hlcd1, dist);
	  LCD_printStr(&hlcd1, pos_dist);
	  LCD_printStr(&hlcd1, cm);
	  LCD_SetCursor(&hlcd1, 1, 0);
	  LCD_printStr(&hlcd1, duty_LCD);
	  LCD_printStr(&hlcd1, duty_print);
	  //LCD_printStr(&hlcd1, cm);



	  //UART communication for calibration*****
//	  if (HAL_UART_Receive(&huart3, (uint8_t *) msg, 12, HAL_MAX_DELAY) == HAL_OK){
//	  		  sscanf(msg, "DUTY_SET=%d", &duty);  // DUTY_SET=073
//	  		  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty);
//	  		  int n = sprintf(msg, "Duty was set to %d\r\n", duty);
//	  	  	  HAL_UART_Transmit(&huart3, (uint8_t *) msg, n, HAL_MAX_DELAY);
//
//	  	  }


	  //APP
//	  int n = sprintf(msg1, "%f", d);
//
//	  HAL_UART_Transmit(&huart3, (uint8_t*) msg1, n, 100);




    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 3;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART3|RCC_PERIPHCLK_I2C1;
  PeriphClkInitStruct.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
  PeriphClkInitStruct.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
