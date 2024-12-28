#include "exti.h"
#include "main.h"


void extiInit(){

	RCC->APB2ENR |= (1U<<0);

	SYSCFG->EXTICR[2] |= (1U<<8); 	// Map PB10 line to EXTI10

	EXTI->IMR |= (1U<<10); 			// Unmask EXTI10 line

	EXTI->RTSR |= (1U<<10);			// Select rising edge trigger

	NVIC_EnableIRQ(EXTI4_15_IRQn);

}


void EXTI4_15_IRQHandler(void) {

	if (EXTI->PR & (1U<<10) ){

		EXTI->PR = (1U<<10); 		// Clear flag
		GPIOB->ODR ^= (1U<<4);		// Activate Buzzer
		GPIOA->ODR ^= (1U<<8);		// Toggle LED

//		for (int i=0;i<10000;i++);

	}
}
