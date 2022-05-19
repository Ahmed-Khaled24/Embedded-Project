#include "stdint.h"
#include "../GPIO/tm4c123gh6pm.h"
	
void systick_vidInit(void){
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0x00FFFFFF;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x05;
}

void systick_vid1msDelay(){
	NVIC_ST_RELOAD_R = 16000 - 1;  
	while((NVIC_ST_CTRL_R&0x00010000)==0) ;
}
void systick_Disable(){
	NVIC_ST_CTRL_R &=~0x00000001;
}//to disable Systick

void systick_Enable(){NVIC_ST_CTRL_R |=  0x01; }//TO enable Systick

void systick_vid1MicroDelay(){
	NVIC_ST_RELOAD_R = 16 - 1;
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R&0x00010000)== 0) ;
}
void systick_vidDelay( uint32_t ms){
	uint32_t i;
	for(i = 0; i < ms; i++){
		systick_vid1msDelay();
	}
}
