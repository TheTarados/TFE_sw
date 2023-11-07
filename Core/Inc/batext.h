/*
 * batext.h
 *
 *  Created on: 30 Apr 2023
 *      Author: brock
 */

#ifndef INC_BATEXT_H_
#define INC_BATEXT_H_

#include "main.h"

#define ADC_BUF_SIZE 512

void batext_power_on(void);
void batext_power_off(void);
void batext_choose_gain(uint8_t gain);
int batext_is_card_inserted(void);
int batext_SD_write(const void *data, uint32_t size);

extern ADC_HandleTypeDef hadc;
extern TIM_HandleTypeDef htim1;

#endif /* INC_BATEXT_H_ */
