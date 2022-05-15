#include "Interrupt.h"
uint8_t PN;
void (*F)(void);
void Interrupt_init(uint8_t pn)
{
    PN = pn;
	 
	
	GPIO_DIO_vidPinInit(GPIO_PORTF,pn);
	GPIO_vidSetPinDirection(GPIO_PORTF,pn,0);
	GPIO_vidSetPinPullUpRes(GPIO_PORTF,pn,1);
    
    /* configure PORTF4, 0 for falling edge trigger interrupt */
	CLEAR_BIT(GPIO_PORTF_IS_R,pn);/* make bit 4, 0 edge sensitive */
  CLEAR_BIT(GPIO_PORTF_IBE_R,pn);/* trigger is controlled by IEV */
  CLEAR_BIT(GPIO_PORTF_IEV_R,pn);/* falling edge trigger */
	
	
	SET_BIT(GPIO_PORTF_ICR_R,pn);/* clear any prior interrupt */
  SET_BIT(GPIO_PORTF_IM_R,pn);/* unmask interrupt */
  
  
  

    /* enable interrupt in NVIC and set priority to 3 */
   NVIC->IP[30] = 3 << 5;     /* set interrupt priority to 3 */
   NVIC->ISER[0] |= (1<<30);  /* enable IRQ30 (D30 of ISER[0]) */

    
    
}

/* SW1 is connected to PF4 pin, SW2 is connected to PF0. */
/* Both of them trigger PORTF falling edge interrupt */
void GPIOF_setHandler(void (*f)(void))
{	
	F = f;
}
void GPIOF_Handler(void)
{	
	F();
	SET_BIT(GPIO_PORTF_ICR_R,PN);/* clear the interrupt flag */
}
