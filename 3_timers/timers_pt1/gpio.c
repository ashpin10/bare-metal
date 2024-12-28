#include "gpio.h"

void gpioInit() {

    RCC->AHBENR = RCC->AHBENR | (1<<17);

    GPIOA->MODER = GPIOA->MODER | (1<<10);

    GPIOA->OTYPER = GPIOA->OTYPER & ~(1<<5);

    GPIOA->ODR = GPIOA->ODR | (1<<5);

}