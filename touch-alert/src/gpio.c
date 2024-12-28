#include "main.h"
#include "gpio.h"

// PA8 	- LED
// PB10 - Touch sensing
// PB4 	- Buzzer

void gpioInit(void) {
	RCC->AHBENR |= (1U<<17) | (1U<<18);

	GPIOB->MODER &= ~(3U<<20); 			// PB10 - Touch Sensor Input mode
	GPIOB->PUPDR |= (2U<<20);

	GPIOA->MODER |= (1U<<16);  			// PA8 - LED Output Mode
	GPIOB->MODER |= (1U<<8);  			// PB4 - Buzzer Output Mode


}
