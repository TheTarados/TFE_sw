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
	print_now("Begin power on\r\n");
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	print_now("BatExt power ON\r\n");
	HAL_Delay(100); // for card insert cap charge
	if(!batext_is_card_inserted()) {
		print_now("Error while powering on : No card inserted\r\n");
		return;
	} else {
		print_now("Success : Card is inserted\r\n");
	}
	batext_SD_init();
	HAL_Delay(1000); // more delays between steps may be required at initialisation otherwise it sometimes fails
	batext_AFE_init();
	batext_choose_gain(3);

	HAL_Delay(100);
	fres = f_open(&fil, "MYTEST", FA_WRITE | FA_OPEN_APPEND);
	if(fres != FR_OK) {
		print_error("f_open error\n", fres);
	}
}
void batext_power_off(void)
{
	batext_AFE_deinit();
	batext_SD_deinit();
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	print_now("BatExt power OFF\r\n");
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
		print_now("Error while enabling timer TIM1\r\n");
		Error_Handler();
	}
	if (HAL_ADC_Start_DMA(&hadc, (uint32_t *)ADCDoubleBuf, 2*ADC_BUF_SIZE) != HAL_OK) {
		print_now("Error while starting the DMA\r\n");
		Error_Handler();
	}
}

void batext_AFE_deinit(void)
{
	if (HAL_ADC_Stop_DMA(&hadc) != HAL_OK) {
		print_now("Error while stopping the DMA\r\n");
		Error_Handler();
	}
	if (HAL_TIM_Base_Stop(&htim1) != HAL_OK) {
		print_now("Error while disabling timer TIM1\r\n");
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
		print_now("Error: ADC Data buffer full\r\n");
		Error_Handler();
	}
	ADCDataRdy[buf_cplt] = 1;

	//print_error("ADC Callback : buffer\n", buf_cplt);

	//start_cycle_count();
	batext_SD_write((const void *) ADCData[buf_cplt], ADC_BUF_SIZE*S_SIZE); // 2 bytes per uint16
	//stop_cycle_count("SD Write");
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
		print_error("f_mount error\n", fres);
		Error_Handler();
	}

	// Statistiques
	DWORD free_clusters, free_sectors, total_sectors;
	FATFS* getFreeFs;
	fres = f_getfree("", &free_clusters, &getFreeFs);
	if (fres != FR_OK) {
		print_error("f_getfree error\n", fres);
		Error_Handler();
	}
	total_sectors = (getFreeFs->n_fatent - 2) * getFreeFs->csize;
	free_sectors = free_clusters * getFreeFs->csize;
	print_now("SD card stats:\r\n");
	print_error("KiB total drive space:\n", total_sectors / 2);
	print_error("KiB available:\n" , free_sectors / 2);
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
		print_error("f_write error, trying to recover\n", fres);
		batext_SD_deinit();
		batext_SD_init();
		HAL_Delay(1000);
		fres = f_open(&fil, "TEST", FA_WRITE | FA_OPEN_APPEND);
		if(fres != FR_OK) {
			print_error("f_open error\n", fres);
		}
		fres = f_write(&fil, data, size, &written); //If we still fail, it seems dead
		return fres;
	}
	if(written != size) {
		print_now("f_write error : did not write all the bytes\r\n");
	}
	return FR_OK;
}
