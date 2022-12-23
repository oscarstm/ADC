#include "stm32f4xx.h"
#include "clk_user.h"
#include "adc_user.h"

uint16_t data;

int main(void) {
	clk_user();
	ADC1_Init();

	ADC1->CR2 |= (ADC_CR2_ADON);
	ADC1->CR2 |= (ADC_CR2_SWSTART);

	while (1) {
		while (!(ADC1->SR & (ADC_SR_EOC))) {
			//
		}
		data = ADC1->DR;
	}

}

