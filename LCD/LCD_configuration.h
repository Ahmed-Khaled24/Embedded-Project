#ifndef LCD_CONFIGURATION
#define LCD_CONFIGURATION
#include "../GPIO/GPIO_driver.h"

// Define LCD pins numbers in their port.
#define LCD_PD0		0
#define LCD_PD1		1
#define LCD_PD2		4
#define LCD_PD3		5
#define LCD_PD4		4
#define LCD_PD5		5
#define LCD_PD6		6
#define LCD_PD7		7
#define LCD_PRS		4
#define LCD_PE		5

// Define LCD data pins port-connection.
#define LCD_PD0_PORT		GPIO_PORTB
#define LCD_PD1_PORT		GPIO_PORTB
#define LCD_PD2_PORT		GPIO_PORTE
#define LCD_PD3_PORT		GPIO_PORTE
#define LCD_PD4_PORT		GPIO_PORTB
#define LCD_PD5_PORT		GPIO_PORTA
#define LCD_PD6_PORT		GPIO_PORTA
#define LCD_PD7_PORT		GPIO_PORTA

// Define LCD RS, E pins port-connection
#define LCD_PRS_PORT		GPIO_PORTA
#define LCD_PE_PORT			GPIO_PORTB

#endif
