#include "stdint.h"
#include "tm4c123gh6pm.h"
	
void systic_vidInit(void){
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0x00FFFFFF;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x05;
}

void systic_vid1msDelay(){
	NVIC_ST_RELOAD_R = 8000 - 1;  //delay of 1ms is actually 8000 cycles not 80000 (found by experimenting  that the bus clock frequency of our kit is 8MHz not 80MHz)
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R&0x00010000)==0) ;
}
void systic_vid1MicroDelay(){
	NVIC_ST_RELOAD_R = 8 - 1;
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R&0x00010000)== 0) ;
}
void systic_vidDelay(unsigned uint32_t ms){
	unsigned uint32_t i;
	for(i = 0; i < ms; i++){
		systic_vid1msDelay();
	}
}
