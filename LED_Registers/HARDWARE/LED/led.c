#include "led.h"
#include "stm32f10x.h"

void LED_Init(void){
	RCC->APB2ENR |= 1 << 3;
	RCC->APB2ENR |= 1 << 6;
	
	GPIOB->CRL &= 0xFF0FFFFF;
	GPIOB->CRL |= 0x00300000;
	GPIOB->ODR |= 1 << 5;
	
	GPIOE->CRL &= 0xFF0FFFFF;
	GPIOE->CRL |= 0x00300000;
	GPIOE->ODR |= 1 << 5;	
	
}
