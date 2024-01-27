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
#include "crc.h"
#include "dma.h"
#include "app_fatfs.h"
#include "usart.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"
#include "app_x-cube-ai.h"

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
  MX_CRC_Init();
  MX_X_CUBE_AI_Init();
  /* USER CODE BEGIN 2 */

  // Print banner and blink LED //
  print_now("\n\nHello world!\n\r\n");

  blink(200);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  #if DEBUG_VEC_COMP
  int16_t in[512] =  { 2047,2879,3568,3993,4082,3819,3250,2472,1621, 843, 274,  11, 100, 525,
		  1214,2047,2879,3568,3993,4082,3819,3250,2472,1621, 843, 274,  11, 100,
		   525,1214,2047,2879,3568,3993,4082,3819,3250,2472,1621, 843, 274,  11,
		   100, 525,1214,2046,2879,3568,3993,4082,3819,3250,2472,1621, 843, 274,
		    11, 100, 525,1214,2047,2879,3568,3993,4082,3819,3250,2472,1621, 843,
		   274,  11, 100, 525,1214,2046,2879,3568,3993,4082,3819,3250,2472,1621,
		   843, 274,  11, 100, 525,1214,2046,2879,3568,3993,4082,3819,3250,2472,
		  1621, 843, 274,  11, 100, 525,1214,2046,2879,3568,3993,4082,3819,3250,
		  2472,1621, 843, 274,  11, 100, 525,1214,2047,2879,3568,3993,4082,3819,
		  3250,2472,1621, 843, 274,  11, 100, 525,1214,2046,2879,3568,3993,4082,
		  3819,3250,2472,1621, 843, 274,  11, 100, 525,1214,2046,2879,3568,3993,
		  4082,3819,3250,2472,1621, 843, 274,  11, 100, 525,1214,2047,2879,3568,
		  3993,4082,3819,3250,2472,1621, 843, 274,  11, 100, 525,1214,2046,2879,
		  3568,3993,4082,3819,3250,2472,1621, 843, 274,  11, 100, 525,1214,2046,
		  2879,3568,3993,4082,3819,3250,2472,1621, 843, 274,  11, 100, 525,1214,
		  2046,2879,3568,3993,4082,3819,3250,2472,1621, 843, 274,  11, 100, 525,
		  1214,2047,2879,3568,3993,4082,3819,3250,2472,1621, 843, 274,  11, 100,
		   525,1214,2047,2879,3568,3993,4082,3819,3250,2472,1621, 843, 274,  11,
		   100, 525,1214,2046,2879,3568,3993,4082,3819,3250,2472,1621, 843, 274,
		    11, 100, 525,1214,2046,2879,3568,3993,4082,3819,3250,2472,1621, 843,
		   274,  11, 100, 525,1214,2047,2879,3568,3993,4082,3819,3250,2472,1621,
		   843, 274,  11, 100, 525,1214,2046,2879,3568,3993,4082,3819,3250,2472,
		  1621, 843, 274,  11, 100, 525,1214,2047,2879,3568,3993,4082,3819,3250,
		  2472,1621, 843, 274,  11, 100, 525,1214,2047,2879,3568,3993,4082,3819,
		  3250,2472,1621, 843, 274,  11, 100, 525,1214,2046,2879,3568,3993,4082,
		  3819,3250,2472,1621, 843, 274,  11, 100, 525,1214,2046,2879,3568,3993,
		  4082,3819,3250,2472,1621, 843, 274,  11, 100, 525,1214,2047,2879,3568,
		  3993,4082,3819,3250,2472,1621, 843, 274,  11, 100, 525,1214,2046,2879,
		  3568,3993,4082,3819,3250,2472,1621, 843, 274,  11, 100, 525,1214,2047,
		  2879,3568,3993,4082,3819,3250,2472,1621, 843, 274,  11, 100, 525,1214,
		  2046,2879,3568,3993,4082,3819,3250,2472,1621, 843, 274,  11, 100, 525,
		  1214,2046,2879,3568,3993,4082,3819,3250,2472,1621, 843, 274,  11, 100,
		   525,1214,2047,2879,3568,3993,4082,3819,3250,2472,1621, 843, 274,  11,
		   100, 525,1214,2046,2879,3568,3993,4082,3819,3250,2472,1621, 843, 274,
		    11, 100, 525,1214,2047,2879,3568,3993,4082,3819,3250,2472,1621, 843,
		   274,  11, 100, 525,1214,2046,2879,3568,3993,4082,3819,3250,2472,1621,
		   843, 274,  11, 100, 525,1214,2046,2879};
  q7_t out[N_MEL_BIN];
  print_now("In array\r\n");
	for(int i = 0 ; i < 10 ; i++){
		print_int(in[i]);
		print_now(",");
	}
	print_now("\r\n\n");
  vec_computation(in, out);
#endif

  while (1)
  {
	  if(0){
    /* USER CODE END WHILE */

  MX_X_CUBE_AI_Process();
    /* USER CODE BEGIN 3 */
	  }
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
//yes I did my own prints
//No they are not perfect but they are good enough for me

void print_array(uint8_t* array, int len){
#if(VERBOSE)
	HAL_UART_Transmit(&hlpuart1, array, len, 0xFFFF);
#endif
}

void print_now(const char* string){
	print_array((uint8_t *)string, strlen(string));
}

void print_int(int my_int){

#if(VERBOSE)
	if (my_int == 0){
		print_array((uint8_t*)"0", 1);
		return;
	}
	char intbuffer[21]; //Consider we won't have more than 20 digits
	intbuffer[20] = '\0';
	uint8_t negative = 0;

	if(my_int<0){
		negative = 1;
		my_int = -my_int;
	}

	int k = 20;
	while(my_int>0){
		intbuffer[--k]=my_int%10+48;
		my_int /= 10;
	}
	if(negative){
		intbuffer[--k]='-';
	}
	print_now((char*)(intbuffer+k));

#endif
}
void print_error(const char* string, int my_int){
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
	  print_now("ERROR!!!");
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
