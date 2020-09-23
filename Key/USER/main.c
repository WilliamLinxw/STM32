// Beeper in Bits
#include "sys.h"	
#include "delay.h"	
#include "LED.h" 
#include "beep.h" 
#include "key.h"

 int main(void){
	
  u8 key;
	delay_init();	    	
	LED_Init();	
	BEEP_Init();
	KEY_Init();
	LED0 = 0;
	 
	while(1){
		key = KEY_Scan(1);
		if(key){
			switch(key){
				case WKUP_PRES:
					BEEP = !BEEP;
					break;
				case KEY2_PRES:
					LED0 = !LED0;
					break;
				case KEY1_PRES:
					LED1 = !LED1;
					break;
				case KEY0_PRES:
					LED0 = !LED0;
					LED1 = !LED1;
					break;
			}
		}
	}
}
 
