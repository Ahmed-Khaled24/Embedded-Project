#include "Interrupt.h"
void Interrupt_init(uint8_t pn)
{
    
	 
	
	GPIO_DIO_vidPinInit(GPIO_PORTF,pn);
	GPIO_vidSetPinDirection(GPIO_PORTF,pn,0);
	GPIO_vidSetPinPullUpRes(GPIO_PORTF,pn,1);
    
    /* configure PORTF4, 0 for falling edge trigger interrupt */
   	GPIOF->IS  &= ~(1<<pn);        /* make bit 4, 0 edge sensitive */
    	GPIOF->IBE &=~(1<<pn);         /* trigger is controlled by IEV */
    	GPIOF->IEV &= ~(1<<pn);       /* falling edge trigger */
    	GPIOF->ICR |= (1<<pn);          /* clear any prior interrupt */
    	GPIOF->IM  |= (1<<pn);          /* unmask interrupt */
    
    /* enable interrupt in NVIC and set priority to 3 */
    	NVIC->IP[30] = 3 << 5;     /* set interrupt priority to 3 */
    	NVIC->ISER[0] |= (1<<30);  /* enable IRQ30 (D30 of ISER[0]) */

    
    
}

/* SW1 is connected to PF4 pin, SW2 is connected to PF0. */
/* Both of them trigger PORTF falling edge interrupt */
void GPIOF_Handler(void (*f)(void))
{	
	f();
}
