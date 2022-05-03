#include "stdint.h"
#include "D:/Keil/EE319Kware/inc/tm4c123gh6pm.h"

void SystemInit(){}
	
void systick_vidInit(void){
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0x00FFFFFF;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x05;
}

void systick_vid1msDelay(){
	NVIC_ST_RELOAD_R = 8000 - 1;  //delay of 1ms is actually 8000 cycles not 80000 (found by experimenting  that the bus clock frequency of our kit is 8MHz not 80MHz)
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R&0x00010000)==0) ;
}

void systick_vidDelay( uint32_t ms){
	uint32_t i;
	for(i = 0; i < ms; i++){
		systick_vid1msDelay();
	}
}

void RGB_Init(void){
SYSCTL_RCGCGPIO_R|=0x20; //INTIALIZE THE CLOCK OF PORTF
while((SYSCTL_PRGPIO_R & 0x20)==0); //delay
GPIO_PORTF_LOCK_R = 0x4C4F434B; //unlocking the ports have the same value
GPIO_PORTF_CR_R |= 0x0E; //Allow changing pin 3,2,1 in portF
GPIO_PORTF_AMSEL_R &=~0x0E; //disable the analog function
GPIO_PORTF_PCTL_R &=~0x0000FFF0;
GPIO_PORTF_AFSEL_R &=~0x0E; //disable the alternate function
GPIO_PORTF_DIR_R |= 0x0E; //Pin1,2,3 is output
GPIO_PORTF_DEN_R |=0x0E;
GPIO_PORTF_DATA_R &=~0x0E; //intialize pins 1,2,3 to be off
}	



void Interrupt_Init(void){
SYSCTL_RCGCGPIO_R |= 0x00000020; // activate clock for port F
GPIO_PORTF_DIR_R &= ~0x10; // make PF4 in (built-in button)
GPIO_PORTF_DEN_R |= 0x10; // enable digital I/O on PF4
GPIO_PORTF_PUR_R |= 0x10; // enable weak pull-up on PF4
GPIO_PORTF_IS_R &= ~0x10; // PF4 is edge-sensitive
GPIO_PORTF_IBE_R &= ~0x10; // PF4 is not both edges
//PortF Interrupt Initialization
GPIO_PORTF_IEV_R |=0x10; // PF4 RAISING edge event
GPIO_PORTF_ICR_R = 0x10; // clear flag4
GPIO_PORTF_IM_R |= 0x10; // arm interrupt on PF4
NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; // (g) priority 5
NVIC_EN0_R = 0x40000000; // (h) enable interrupt 30 in NVIC
EnableInterrupts(); // (i) Enable global Interrupt flag (I)
}
void GPIOPortF_Handler(void){

	GPIO_PORTF_ICR_R = 0x10; // acknowledge flag4
	RGB_Init();
	while(1){

		GPIO_PORTF_DATA_R ^= 0x0E;
		LCD_vidPause();
		systick_vidDelay(2000);
		
	}
}