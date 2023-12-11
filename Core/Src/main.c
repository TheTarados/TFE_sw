/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "app_fatfs.h"
#include "usart.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "rtc.h"
#include "batext.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */


int timertogglenumber;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void blink(int);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_LPUART1_UART_Init();
  MX_ADC_Init();
  MX_TIM1_Init();
  MX_SPI1_Init();
  MX_FATFS_Init();
  /* USER CODE BEGIN 2 */

  // Print banner and blink LED //
  print_now("\n\nHello world!\n\r\n");

  blink(200);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
#if DEBUG_VEC_COMP
  int8_t in[512] =  { 69, 90, 76, 69, 53, 82, 55,113,122, 48,100, 67, 72,117,  9, 11,  2,105,
		  98,110,124,101, 58, 99, 15, 81, 18,119, 66, 52, 33, 98, 57, 72,  2, 78,
		  77, 78,119, 86, 45, 55, 88,  7, 84, 85, 26, 16, 40, 46, 72, 55,125, 12,
		  26, 20, 82, 32, 59, 31, 20, 14, 83, 17, 24, 46,104, 12,106, 12,124, 59,
		 124, 76, 93,  4, 35, 15, 37, 15, 40, 52,  8, 87, 71, 33, 66, 11, 73,118,
		  40, 84, 16, 90, 36, 23, 74,  2,105,  0, 86, 34, 93,122, 31, 73, 75, 72,
		  28,120, 56,107, 88, 37,103, 50,111, 73,111, 87, 92, 63,121, 81, 53, 77,
		   2, 38, 83, 36, 78, 54, 17, 37, 72, 75, 72, 82, 82, 54,113, 46, 55,113,
		 102, 89, 12,116, 90,126, 18,110, 20, 78, 15,107,102, 72, 51,  8, 88, 57,
		  91,110,123,108,  1, 45, 92, 21, 66,  6, 25,  2,100, 28, 43,117, 89,  4,
		  20, 78, 73, 30,118, 77, 68, 74, 92, 39, 50, 26, 23,119, 93, 62, 28, 32,
		   7, 55, 39, 88, 47, 22,  3,  8, 86, 57, 68,113,125, 27, 84, 33,  2, 96,
		  40, 48, 74,105, 79,110, 34,101, 23,121, 87, 27,120, 92, 32, 27, 65,  3,
		  26, 53, 47, 58, 35, 74,109, 14, 65, 16, 91, 50, 71, 23, 18, 61, 45,119,
		  97, 95,114, 10, 70, 74,122, 37, 30, 12,  2,118, 85, 99, 35, 74,  8, 61,
		 124,111, 42,122, 29,120,119,101, 80,111, 37,107, 78,  1, 44, 18,124, 60,
		  63, 81, 46, 17,104, 24, 64, 28, 12,109,123,122,115, 98, 42, 10, 51, 29,
		  16,  6, 92,  1, 97, 18, 10, 11, 85, 31, 53, 70,109, 92, 34, 16,  7, 38,
		  33, 57, 86, 88, 36, 48, 23,100,  7, 88, 98, 98, 32, 47, 74, 34, 47, 25,
		  58,  5,101,  9, 65, 38, 73,121, 81,  4, 54, 64, 68, 86, 35, 16, 49,121,
		  23,114, 69, 58,112, 58, 91, 50,114, 87, 88, 41, 96, 80, 30, 20,101,121,
		  58, 75,108, 58,120, 73,104,115,103, 20, 79, 50,  7, 53, 32,107,  4,121,
		  45, 45,  2, 23, 50,118, 12,120,110, 57, 41, 29, 78,  4,  1, 54,  8, 31,
		  28, 32, 16,  1, 14, 78,123,125, 51, 20, 81, 62,125,  8, 99, 36, 30, 84,
		  31, 84, 65, 53, 70, 36, 89, 52, 45,105,117,  5, 29, 44,103,125,123,114,
		  37,125, 31, 13,120, 29, 87,  7, 92,111, 34, 48, 47, 95, 30, 21, 57, 38,
		 106, 30, 63,119, 80,110,119, 95, 88,122,126, 57,  9, 37, 19, 53, 16, 76,
		  48,113,122, 69, 34, 75,113, 51, 70, 34, 57, 51, 31, 64, 39, 47, 66, 95,
		  42,117,109,  6, 32, 56, 13, 44};

  print_now("In array\r\n");
	for(int i = 0 ; i < 10 ; i++){
		print_int(in[i]);
		print_now(",");
	}
	print_now("\r\n\n");
  vec_computation(in);
#endif
  while (1)
  {
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

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_11;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the SYSCLKSource, HCLK, PCLK1 and PCLK2 clocks dividers
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK3|RCC_CLOCKTYPE_HCLK
                              |RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1
                              |RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.AHBCLK3Divider = RCC_SYSCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void print_now(char* string){
#if(VERBOSE)
	HAL_UART_Transmit(&hlpuart1, (uint8_t *)string, strlen(string), 0xFFFF);
#endif
}

int intbuffer[20]; //Consider we won't have more than 20 digits
void print_int(int my_int){
#if(VERBOSE)
	if(my_int<0){
		print_now("-");
		my_int = -my_int;
	}
	if (my_int == 0){
		print_now("0");
		return;
	}
	int k = 0;
	while(my_int>0){
		char temp = my_int%10+48;
		intbuffer[k]=temp;
		k++;
		my_int /= 10;
	}
	for(int j = k-1; j >=0; j-=1 ){
		print_now((char*)(intbuffer+j));
	}
#endif
}
void print_error(char* string, int my_int){
#if(VERBOSE)
	print_now(string);
	print_int(my_int);
	print_now("\r\n");
#endif
}


void blink(int time_ms){

	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	HAL_Delay(time_ms);
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}

/* GPIO button press callback */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	//debug_print("GPIO EXTI callback - ");
	if(GPIO_Pin == Button1_Pin) {
		print_now("Button 1\r\n");
		batext_power_on();
		blink(500);
	} else if (GPIO_Pin == Button2_Pin) {
		print_now("Button 2\r\n");
		print_now("Shutting down\r\n");
		batext_power_off();
		blink(500);
	} else {
		print_now("other?\r\n");
	}
}


void HAL_RTCEx_WakeUpTimerEventCallback(RTC_HandleTypeDef *hrtc)
{

	print_now("RTC Wake up !\r\n");
}

volatile uint8_t counting_cycles = 0;

void start_cycle_count() {
	uint32_t prim = __get_PRIMASK();
	__disable_irq();
	if (counting_cycles) {
		print_now("Tried re-entrant cycle counting.\r\n");
		Error_Handler();
	} else {
		counting_cycles = 1;
	}
	if (!prim) {
		__enable_irq();
	}
	DWT->CTRL |= 1 ; // enable the counter
	DWT->CYCCNT = 0; // reset the counter
}
void stop_cycle_count(char *s) {
	uint32_t res = DWT->CYCCNT;
	counting_cycles = 0;
	print_now("[PERF] ");
	print_now(s);
	print_error("Cycles: ", res);
}


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
