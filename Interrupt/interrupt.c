/*
Philopateer Moheb Fouad Barsom
1901202

*/
#include "Interrupt.h"
uint8_t PN;
void (*F)(void);
void (*E)(void);

void InterruptF_init(uint8_t PORT,uint8_t pn)
{
   	 PN = pn;
	 
	
	GPIO_DIO_vidPinInit(PORT,pn);
	GPIO_vidSetPinDirection(PORT,pn,0);
	GPIO_vidSetPinPullUpRes(PORT,pn,1);
    
    /* configure PORTF4, 0 for falling edge trigger interrupt*/
	CLEAR_BIT(PORT,pn);/* make bit 4, 0 edge sensitive */
  	CLEAR_BIT(PORT,pn);/* trigger is controlled by IEV */
  	CLEAR_BIT(PORT,pn);/* falling edge trigger */
	
	
	SET_BIT(PORT,pn);/* clear any prior interrupt */
  	SET_BIT(PORT,pn);/* unmask interrupt */
  
  
    /* enable interrupt in NVIC and set priority to 3 */
   	NVIC->IP[30] = 3 << 5;     /* set interrupt priority to 3 */
   	NVIC->ISER[0] |= (1<<30);  /* enable IRQ30 (D30 of ISER[0]) */    
}



/* SW1 is connected to PF4 pin, SW2 is connected to PF0.,SW3 connected to PE0 */
/* Both of them trigger PORTF and PORTE falling edge interrupt */
//adding interrupt to SW3 for pin0 in PORTE
void GPIOF_setHandler(void (*f)(void))
{	
	F = f;
}
//we make function pointer to make code look more clean
void GPIOE_setHandler(void (*e)(void))
{	
	E = e;
}
void GPIOE_Handler(void){
	E();
	SET_BIT(GPIO_PORTE_ICR_R,PN);/* clear the interrupt flag */


}
void GPIOF_Handler(void)
{	
	F();
	SET_BIT(GPIO_PORTF_ICR_R,PN);/* clear the interrupt flag */
}
