// Beeper in Bits
#include "sys.h"	
#include "delay.h"	
#include "LED.h" 
#include "beep.h" 

 int main(void){
	delay_init();	    	
	LED_Init();	
	BEEP_Init();
	while(1)
	{
		LED1=0;
		BEEP=0;		  
		delay_ms(300);
		LED1=1;	  
		BEEP=1;  
		delay_ms(300);
	}
}
 
