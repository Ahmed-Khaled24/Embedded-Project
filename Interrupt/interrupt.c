/*
Philopateer Moheb Fouad Barsom
1901202

*/
#include "Interrupt.h"
uint8_t PN;
uint8_t PN_E;
void (*F)(void);
void (*E)(void);

void InterruptF_init(uint8_t pn)
{
   	 PN = pn;


	GPIO_DIO_vidPinInit(GPIO_PORTF,pn);
	GPIO_vidSetPinDirection(GPIO_PORTF,pn,0);
	GPIO_vidSetPinPullUpRes(GPIO_PORTF,pn,1);

    /* configure PORTF4, 0 for falling edge trigger interrupt and we will configure also PORTE pin 0 for same conditions for SW3*/
	CLEAR_BIT(GPIO_PORTF_IS_R,pn);/* make bit 4, 0 edge sensitive */
  	CLEAR_BIT(GPIO_PORTF_IBE_R,pn);/* trigger is controlled by IEV */
  	CLEAR_BIT(GPIO_PORTF_IEV_R,pn);/* falling edge trigger */

	SET_BIT(GPIO_PORTF_ICR_R,pn);/* clear any prior interrupt */
  	SET_BIT(GPIO_PORTF_IM_R,pn);/* unmask interrupt */


    /* enable interrupt in NVIC and set priority to 3 */
   	NVIC->IP[30] = 3 << 5;     /* set interrupt priority to 3 */
   	NVIC->ISER[0] |= (1<<30);  /* enable IRQ30 (D30 of ISER[0]) */
}
void InterruptE_init(uint8_t pn)
{
   	 PN_E = pn;


	GPIO_DIO_vidPinInit(GPIO_PORTE,pn);
	GPIO_vidSetPinDirection(GPIO_PORTE,pn,0);
	GPIO_vidSetPinPullUpRes(GPIO_PORTE,pn,1);
	

    /* configure PORTE0, 0 for falling edge trigger interrupt for SW3*/
	CLEAR_BIT(GPIO_PORTE_IS_R,pn);/* make bit 0 edge sensitive */
  	CLEAR_BIT(GPIO_PORTE_IBE_R,pn);/* trigger is controlled by IEV */
  	CLEAR_BIT(GPIO_PORTE_IEV_R,pn);/* falling edge trigger */
   
	SET_BIT(GPIO_PORTE_ICR_R,pn);/* clear any prior interrupt */
  	SET_BIT(GPIO_PORTE_IM_R,pn);/* unmask interrupt */


    /* enable interrupt in NVIC and set priority to 3 */
   	NVIC_PRI1_R = (NVIC_PRI1_R&0xFFFFFF1F)|0x000000E0; // (g) priority 7
	NVIC_EN0_R = 0x00000010; // (h) enable interrupt 4 in NVIC
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
	SET_BIT(GPIO_PORTE_ICR_R,PN_E);/* clear the interrupt flag */


}
void GPIOF_Handler(void)
{	
	F();
	SET_BIT(GPIO_PORTF_ICR_R,PN);/* clear the interrupt flag */
}
