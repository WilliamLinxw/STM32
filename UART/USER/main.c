#include "stm32f10x.h"
#include "uart.h"


int main(void){	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	My_USART_Init();
	while(1);
}
