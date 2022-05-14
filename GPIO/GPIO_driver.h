/*********************************************************************

//created by Ghaith Bassam Zaza 21/4/22
last edited 23/4/22

*********************************************************************/
/*********************************************************************

to use pin as digital io:

GPIO_DIO_vidPinInit(u8PortNumberCpy,u8PinNumberCpy);
GPIO_vidSetPinDirection(u8PortNumberCpy, u8PinNumberCpy, u8DirectionCpy);

***********************************************************

to use port as digital io:

GPIO_DIO_vidPortInit(u8PortNumberCpy);
GPIO_vidSetPortDirection(uint8_t u8PortNumberCpy, uint8_t u8ValueCpy);

***********************************************************

to set output digital signal

for  pin:		GPIO_vidSetPinValue(u8PortNumberCpy, u8PinNumberCpy, u8ValueCpy);
for  port:	GPIO_vidSetPortValue(u8PortNumberCpy, u8ValueCpy);

***********************************************************

to read input digital signal:

for  port:	GPIO_u8GetPortValue(u8PortNumberCpy);
for  pin:		GPIO_u8GetPinValue(u8PortNumberCpy,u8PinNumberCpy);

*********************************************************************/
#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "Macros.h"

#define GPIO_PORTA        0
#define GPIO_PORTB        1
#define GPIO_PORTC        2
#define GPIO_PORTD        3
#define GPIO_PORTE        4
#define GPIO_PORTF        5

#define High 							1
#define Low 							0

void GPIO_vidSetPinValue(uint8_t u8PortNumberCpy, uint8_t u8PinNumberCpy, uint8_t u8ValueCpy);// set value (High | low) to output pins

uint8_t GPIO_u8GetPinValue(uint8_t u8PortNumberCpy, uint8_t u8PinNumberCpy);// get value (High | low) from output pins

void GPIO_vidSetPinDirection(uint8_t u8PortNumberCpy, uint8_t u8PinNumberCpy, uint8_t u8DirectionCpy);//set direction of io pin

void GPIO_vidSetPortDirection(uint8_t u8PortNumberCpy, uint8_t u8ValueCpy);// set dierections of all pins of io port (can be different min 0x00 for all pins to be input  max 0xFF for all pins to be output
																																							// for port f max is 0x1F for port E max is ox3F
void GPIO_vidSetPortValue(uint8_t u8PortNumberCpy, uint8_t u8ValueCpy);// set value of all pins of the Port -follows the same rules as SetPortDirection

uint8_t GPIO_u8GetPortValue(uint8_t u8PortNumberCpy);// get values of pins of Port

void GPIO_vidActPinAlternateFunction(uint8_t u8PortNumberCpy, uint8_t u8PinNumberCpy, uint8_t u8ValueCpy);

void GPIO_vidActPortAlternateFunction(uint8_t u8PortNumberCpy, uint8_t u8ValueCpy);

void GPIO_vidSetPinDigitalEnable(uint8_t u8PortNumberCpy, uint8_t u8PinNumberCpy, uint8_t u8ValueCpy);

void GPIO_vidSetPortDigitalEnable(uint8_t u8PortNumberCpy, uint8_t u8ValueCpy);

void GPIO_vidSetPinAnalogEnable(uint8_t u8PortNumberCpy, uint8_t u8PinNumberCpy, uint8_t u8ValueCpy);

void GPIO_vidSetPortAnalogEnable(uint8_t u8PortNumberCpy, uint8_t u8ValueCpy);//activate pull up resistor of port follows previous portFunctions rules

void GPIO_vidSetPinPullUpRes(uint8_t u8PortNumberCpy, uint8_t u8PinNumberCpy, uint8_t u8ValueCpy);//activate pull up resistor of pin

void GPIO_vidSetPortPullUpRes(uint8_t u8PortNumberCpy, uint8_t u8ValueCpy);//activate pull up resistor of pin

void GPIO_vidSetPinPullDownRes(uint8_t u8PortNumberCpy, uint8_t u8PinNumberCpy, uint8_t u8ValueCpy);//activate pull Down resistor of pin

void GPIO_vidSetPortPullDownRes(uint8_t u8PortNumberCpy, uint8_t u8ValueCpy);//activate pull Down resistor of port follows previous portFunctions rules

void GPIO_vidClkActivate(uint8_t u8PortNumberCpy,uint8_t u8ValueCpy);

void GPIO_vidSetPortAlternateFunc(uint8_t u8PortNumberCpy,uint8_t u8PCTLValCpy);

void GPIO_vidSetPinAlternateFunc(uint8_t u8PortNumberCpy,uint8_t u8PinNumberCpy,uint32_t u8PCTLValCpy);

void GPIO_vidUnlockPF0(void);

void GPIO_vidUnlockPD7(void);

void GPIO_DIO_vidPortInit(uint8_t u8PortNumberCpy);//intialize port

void GPIO_DIO_vidPinInit(uint8_t u8PortNumberCpy,uint8_t u8PinNumberCpy);//initialize pin



#endif
