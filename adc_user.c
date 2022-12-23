/*
 * adc_user.c
 *
 *  Created on: Dec 21, 2022
 *      Author: oscar
 */

#include "adc_user.h"

void ADC1_Init(void) {
	/*
	 * GPIO Settings: ADC1_IN5 (PA5)
	 */
	RCC->APB2ENR |= (RCC_APB2ENR_ADC1EN);
	RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOAEN);

	GPIOA->MODER |= (GPIO_MODER_MODER5);
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR5);
	/*
	 * ADC Settings
	 */
	ADC->CCR |= (ADC_CCR_ADCPRE_0);
	ADC->CCR &= ~(ADC_CCR_ADCPRE_1);

	ADC1->CR1 &= ~(ADC_CR1_RES);

	ADC1->CR2 |= (ADC_CR2_CONT);
	ADC1->CR2 |= (ADC_CR2_EOCS);
	ADC1->CR2 &= ~(ADC_CR2_ALIGN);
	/*
	 * ADC_Regular_ConversionMode
	 */
	ADC1->SQR1 &= ~(ADC_SQR1_L);

	ADC1->SQR3 |= (ADC_SQR3_SQ1_0 | ADC_SQR3_SQ1_2);
	ADC1->SQR3 &= ~(ADC_SQR3_SQ1_1);

	ADC1->SMPR2 |= (ADC_SMPR2_SMP5_0);
	ADC1->SMPR2 &= ~(ADC_SMPR2_SMP5_1);
	ADC1->SMPR2 &= ~(ADC_SMPR2_SMP5_2);
}
