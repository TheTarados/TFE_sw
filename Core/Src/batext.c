/*
 * batext.c
 *
 *  Created on: Apr 30, 2023
 *      Author: brock
 */

#include "batext.h"
#include "app_fatfs.h"
#include "spectrogram_tables.h"

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

int init_sd_power_on(void){
	if(!batext_is_card_inserted()) {
		print_now("Error while powering on : No card inserted\r\n");
		return 1;
	} else {
		print_now("Success : Card is inserted\r\n");
	}
	batext_SD_init();
	HAL_Delay(1000);
	fres = f_open(&fil, "MYTEST", FA_WRITE | FA_OPEN_APPEND);
	if(fres != FR_OK) {
		print_error("f_open error\n", fres);
		return 1;
	}
	return 0;
}

void batext_power_on(void)
{
	print_now("Begin power on\r\n");
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	print_now("BatExt power ON\r\n");
	HAL_Delay(100); // for card insert cap charge

#if SAVE_TO_SD
	if(init_sd_power_on())return;
#endif
	HAL_Delay(1000); // more delays between steps may be required at initialisation otherwise it sometimes fails
	batext_AFE_init();
	batext_choose_gain(3);

}
void batext_power_off(void)
{
	batext_AFE_deinit();
#if SAVE_TO_SD
	batext_SD_deinit();
#endif
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

#if SAVE_TO_SD
static void Save_Callback(int buf_cplt) {
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

#endif

#if !SAVE_TO_SD
q15_t buf     [ ADC_BUF_SIZE ]; // Windowed samples
q15_t fft_buf     [ 2 * ADC_BUF_SIZE ]; // Windowed samples
q15_t melvec [64];
q63_t temp_vak = 0;
void vec_computation(q7_t* in) {
	arm_q7_to_q15(in, buf, ADC_BUF_SIZE);

	print_now("after q7 to q15\r\n");
	for(int i = 0 ; i < 10 ; i++){
		print_int(buf[i]);
		print_now(",");
	}
	print_now("\r\n\n");




	arm_mult_q15(buf, hamming_window, buf, ADC_BUF_SIZE);
	print_now("after mult\r\n");
	for(int i = 0 ; i < 10 ; i++){
		print_int(buf[i]);
		print_now(",");
	}
	print_now("\r\n\n");

	arm_rfft_instance_q15 rfft_inst;
	arm_rfft_init_q15(&rfft_inst, ADC_BUF_SIZE, 0, 1);
	arm_rfft_q15( &rfft_inst, buf, fft_buf);

	print_now("after fft\r\n");
	for(int i = 0 ; i < 10 ; i++){
		print_int(fft_buf[i]);
		print_now(",");
	}
	print_now("\r\n\n");

	arm_shift_q15(fft_buf, 7,buf, ADC_BUF_SIZE/2);
	arm_cmplx_mag_q15(buf, buf, ADC_BUF_SIZE/2);

	for(int i = 0 ; i < 10; i++){
		arm_dot_prod_q15(buf+s_pos[i],ls[i],l_lens[i], &temp_vak);
		melvec[i] = (q15_t)(temp_vak>>3);
	}
	/*
	arm_mat_mult_fast_q15(&hz2mel_inst, &fftmag_inst, &melvec_inst, buf);
	*/
	for(int i = 0 ; i < 64 ; i++){
		print_int(melvec[i]);
		print_now(",");
	}
	print_now("\r\n");
}

static void Spec_Callback(int buf_cplt) {
	vec_computation((q7_t*)ADCData[buf_cplt]);
}

#endif

void eff_Callback(int i){
#if !SAVE_TO_SD
	Spec_Callback(i);
#else
	Save_Callback(i);
#endif

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	eff_Callback(1);
}

void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef *hadc)
{
	eff_Callback(0);
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
