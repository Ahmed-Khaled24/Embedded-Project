#include "stdint.h"
#include "../GPIO/tm4c123gh6pm.h"
#include "../Systick/Systick.h"



unsigned char InterruptsControl;

void Interrupt_Init(void){
SYSCTL_RCGCGPIO_R |= 0x00000020; // activate clock for port F
GPIO_PORTF_DIR_R &= ~0x10; // make PF4 in (built-in button)
GPIO_PORTF_DEN_R |= 0x10; // enable digital I/O on PF4
GPIO_PORTF_PUR_R |= 0x10; // enable weak pull-up on PF4
GPIO_PORTF_IS_R &= ~0x10; // PF4 is edge-sensitive
GPIO_PORTF_IBE_R &= ~0x10; // PF4 is not both edges
//PortF Interrupt Initialization
InterruptsControl++;
GPIO_PORTF_IEV_R |=0x10; // PF4 RAISING edge event
GPIO_PORTF_ICR_R = 0x10; // clear flag4
GPIO_PORTF_IM_R |= 0x10; // arm interrupt on PF4
NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; // (g) priority 5
NVIC_EN0_R = 0x40000000; // (h) enable interrupt 30 in NVIC
EnableInterrupts(); // (i) Enable global Interrupt flag (I)
}
void GPIOPortF_Handler(void){

	GPIO_PORTF_ICR_R = 0x10; // acknowledge flag4
	GPIO_DIO_vidPortInit(GPIO_PORTF); //initialize port F
	while(1){

		
		if(InterruptsControl>1){
		GPIO_PORTF_DATA_R ^= 0x0E;
		LCD_vidPause();
		systick_vidDelay(2000);
		}
		else if(InterruptsControl==1){
			//pause(Systic delay) or LCD function
		
		}
	}
}
