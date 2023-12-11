/*
 * batext.h
 *
 *  Created on: 30 Apr 2023
 *      Author: brock
 */

#ifndef INC_BATEXT_H_
#define INC_BATEXT_H_

#include "main.h"
#include "arm_math.h"

#define ADC_BUF_SIZE	512
#define SAVE_RAW_AUDIO_TO_SD 0
#define SAVE_SPEC_NOT_RAW 1
#define DEBUG_VEC_COMP 0
#define PRINT_VEC 1

void batext_power_on(void);
void batext_power_off(void);
void batext_choose_gain(uint8_t gain);
int batext_is_card_inserted(void);
int batext_SD_write(const void *data, uint32_t size);
void vec_computation(q7_t* in);

extern ADC_HandleTypeDef hadc;
extern TIM_HandleTypeDef htim1;

#endif /* INC_BATEXT_H_ */
