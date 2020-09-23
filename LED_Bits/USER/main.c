#include "stm32f10x.h"
#include "LED.h"
#include "delay.h"

int main(void){	
	delay_init();
	LED_Init();
	
	while(1){
		PBout(5) = 1;
		delay_ms(500);
		
		PBout(5) = 0;
		PEout(5) = 1;
		delay_ms(500);
		
		PEout(5) = 0;
	}
}
