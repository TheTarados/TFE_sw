/*
 * batext.c
 *
 *  Created on: Apr 30, 2023
 *      Author: brock
 */

#include "batext.h"
#include "app_fatfs.h"


void batext_AFE_init(void);
void batext_AFE_deinit(void);
void batext_SD_init(void);
void batext_SD_deinit(void);
int batext_SD_write(const void *data, uint32_t size);

typedef uint8_t SAMPLE;
#define S_SIZE sizeof(SAMPLE)

FATFS FatFs; 	//Fatfs handle
FIL fil; 		//File handle
FRESULT fres; //Result after operation

void batext_power_on(void)
{
	APP_PRINTF("Begin power on\r\n");
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	debug_print("BatExt power ON\r\n");
	HAL_Delay(100); // for card insert cap charge
	if(!batext_is_card_inserted()) {
		debug_print("Error while powering on : No card inserted\r\n");
		return;
	} else {
		debug_print("Success : Card is inserted\r\n");
	}
	batext_SD_init();
	HAL_Delay(1000); // more delays between steps may be required at initialisation otherwise it sometimes fails
	batext_AFE_init();
	batext_choose_gain(3);

	HAL_Delay(100);
	fres = f_open(&fil, "TEST", FA_WRITE | FA_OPEN_APPEND);
	if(fres != FR_OK) {
		APP_PRINTF("f_open error (%i)\r\n", fres);
	}
}
void batext_power_off(void)
{
	batext_AFE_deinit();
	batext_SD_deinit();
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	debug_print("BatExt power OFF\r\n");
}



/*******************
 *
 * AFE
 *
 *******************/

static volatile SAMPLE ADCDoubleBuf[2*ADC_BUF_SIZE]; /* ADC group regular conversion data (array of data) */
static volatile SAMPLE* ADCData[2] = {&ADCDoubleBuf[0], &ADCDoubleBuf[ADC_BUF_SIZE]};
static volatile uint8_t ADCDataRdy[2] = {0, 0};


void batext_AFE_init(void)
{
	/*if (HAL_ADCEx_Calibration_Start(&hadc) != HAL_OK) {
		debug_print("Error while calibrating the ADC\r\n");
		Error_Handler();
	}*/
	if (HAL_TIM_Base_Start(&htim1) != HAL_OK) {
		debug_print("Error while enabling timer TIM1\r\n");
		Error_Handler();
	}
	if (HAL_ADC_Start_DMA(&hadc, (uint32_t *)ADCDoubleBuf, 2*ADC_BUF_SIZE) != HAL_OK) {
		debug_print("Error while starting the DMA\r\n");
		Error_Handler();
	}
}

void batext_AFE_deinit(void)
{
	if (HAL_ADC_Stop_DMA(&hadc) != HAL_OK) {
		debug_print("Error while stopping the DMA\r\n");
		Error_Handler();
	}
	if (HAL_TIM_Base_Stop(&htim1) != HAL_OK) {
		debug_print("Error while disabling timer TIM1\r\n");
		Error_Handler();
	}
}

/*
 *	gain : 0 disconnected - 1 33 dB - 2 43 dB - 3 53 dB
 */
void batext_choose_gain(uint8_t gain)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, gain & 0x01);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, (gain & 0x02) >> 1);
}

static void ADC_Callback(int buf_cplt) {
	if (ADCDataRdy[1-buf_cplt]) {
		debug_print("Error: ADC Data buffer full\r\n");
		Error_Handler();
	}
	ADCDataRdy[buf_cplt] = 1;

	//APP_PRINTF("ADC Callback : buffer %d\r\n", buf_cplt);

//	start_cycle_count();
	batext_SD_write((const void *) ADCData[buf_cplt], ADC_BUF_SIZE*S_SIZE); // 2 bytes per uint16
//	stop_cycle_count("SD Write");
	//APP_PRINTF("Wrote %d bytes\r\n", ADC_BUF_SIZE*S_SIZE);

	ADCDataRdy[buf_cplt] = 0;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	ADC_Callback(1);
}

void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef *hadc)
{
	ADC_Callback(0);
}

/*******************
 *
 * µSD
 *
 *******************/


int batext_is_card_inserted(void)
{
	return HAL_GPIO_ReadPin(BatExt_CD_GPIO_Port, BatExt_CD_Pin);
}


void batext_SD_init(void)
{
	// Mount
	HAL_Delay(1000); // to let time for SD to settle if just inserted
	fres = f_mount(&FatFs, "", 1); //1=mount now
	if (fres != FR_OK) {
		APP_PRINTF("f_mount error (%i)\r\n", fres);
		Error_Handler();
	}

	// Statistiques
	DWORD free_clusters, free_sectors, total_sectors;
	FATFS* getFreeFs;
	fres = f_getfree("", &free_clusters, &getFreeFs);
	if (fres != FR_OK) {
		APP_PRINTF("f_getfree error (%i)\r\n", fres);
		Error_Handler();
	}
	total_sectors = (getFreeFs->n_fatent - 2) * getFreeFs->csize;
	free_sectors = free_clusters * getFreeFs->csize;
	APP_PRINTF("SD card stats:\r\n%u KiB total drive space.\r\n%u KiB available.\r\n", total_sectors / 2, free_sectors / 2);
}


void batext_SD_deinit(void)
{
	f_close(&fil);
	HAL_Delay(1000);

	f_mount(NULL, "", 0);
}


int batext_SD_write(const void *data, uint32_t size)
{
	UINT written;
	fres = f_write(&fil, data, size, &written);
	if(fres != FR_OK) {
		APP_PRINTF("f_write error (%i), trying to recover\r\n", fres);
		batext_SD_deinit();
		batext_SD_init();
		HAL_Delay(1000);
		fres = f_open(&fil, "TEST", FA_WRITE | FA_OPEN_APPEND);
		if(fres != FR_OK) {
			APP_PRINTF("f_open error (%i)\r\n", fres);
		}
		fres = f_write(&fil, data, size, &written); //If we still fail, it seems dead
		return fres;
	}
	if(written != size) {
		APP_PRINTF("f_write error : did not write all the bytes\r\n");
	}
	return FR_OK;
}
