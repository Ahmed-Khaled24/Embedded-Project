/*
 * KEYPAD_program.c
 *
 * Created: 1/5/2022
 *  Author: Malek Abdelrhman
 */

#include <stdint.h>// for standerd types 
#include "../GPIO/GPIO_driver.h" 
#include "Keypad_configration.h"
#include "keypad_private.h"
#include "Keypad_interface.h"
#include "../Systick/Systick.h"

static uint8_t i = 0;
void KEYPAD_init(void)
{
	i = 0;
#if ( KEYPAD_u8PULLUP == KEYPAD_u8INTERNAL)
	//make all culoms =1

	GPIO_DIO_vidPinInit(KEYPAD_u8COL1_PORT, KEYPAD_u8COL1);// intiate for pins 

	GPIO_DIO_vidPinInit(KEYPAD_u8COL2_PORT, KEYPAD_u8COL2);// intiate 

	GPIO_DIO_vidPinInit(KEYPAD_u8COL3_PORT, KEYPAD_u8COL3);// intiate 

	GPIO_DIO_vidPinInit(KEYPAD_u8COL4_PORT, KEYPAD_u8COL4);// intiate 

	GPIO_vidSetPinDirection(KEYPAD_u8COL1_PORT, KEYPAD_u8COL1, 1); 

	GPIO_vidSetPinDirection(KEYPAD_u8COL2_PORT, KEYPAD_u8COL2, 1);

	GPIO_vidSetPinDirection(KEYPAD_u8COL3_PORT, KEYPAD_u8COL3, 1);

	GPIO_vidSetPinDirection(KEYPAD_u8COL4_PORT, KEYPAD_u8COL4, 1);

	//make all rows = 0
	GPIO_DIO_vidPinInit(KEYPAD_u8ROW1_PORT, KEYPAD_u8ROW1);// intiate for pins 

	GPIO_DIO_vidPinInit(KEYPAD_u8ROW2_PORT, KEYPAD_u8ROW2);// intiate 

	GPIO_DIO_vidPinInit(KEYPAD_u8ROW3_PORT, KEYPAD_u8ROW3);// intiate 

	GPIO_DIO_vidPinInit(KEYPAD_u8ROW4_PORT, KEYPAD_u8ROW4);// intiate

	
	GPIO_vidSetPinDirection(KEYPAD_u8ROW1_PORT, KEYPAD_u8ROW1, 0);

	GPIO_vidSetPinDirection(KEYPAD_u8ROW2_PORT, KEYPAD_u8ROW2, 0);
	
	GPIO_vidSetPinDirection(KEYPAD_u8ROW3_PORT, KEYPAD_u8ROW3, 0);

	GPIO_vidSetPinDirection(KEYPAD_u8ROW4_PORT, KEYPAD_u8ROW4, 0);

	
	
	GPIO_vidSetPinValue(KEYPAD_u8COL1_PORT, KEYPAD_u8COL1, 1); 

	GPIO_vidSetPinValue(KEYPAD_u8COL2_PORT, KEYPAD_u8COL2, 1);

	GPIO_vidSetPinValue(KEYPAD_u8COL3_PORT, KEYPAD_u8COL3, 1);
	
	GPIO_vidSetPinValue(KEYPAD_u8COL4_PORT, KEYPAD_u8COL4, 1);

	GPIO_vidSetPinPullUpRes(KEYPAD_u8ROW1_PORT, KEYPAD_u8ROW1, 1);
	
	GPIO_vidSetPinPullUpRes(KEYPAD_u8ROW2_PORT, KEYPAD_u8ROW2, 1);

	GPIO_vidSetPinPullUpRes(KEYPAD_u8ROW3_PORT, KEYPAD_u8ROW3, 1);

	GPIO_vidSetPinPullUpRes(KEYPAD_u8ROW4_PORT, KEYPAD_u8ROW4, 1);
	

#endif

}


uint8_t KEYPAD_u8GetButton(void)// in KEYPAD_interface that i didn't make yet
{
	
		uint8_t Button = '\0'; // set unsigned 8 bit to null

	
	/*Apply sequence 0 */
	
	GPIO_vidSetPinValue(KEYPAD_u8COL1_PORT, KEYPAD_u8COL1, 0);
	
	GPIO_vidSetPinValue(KEYPAD_u8COL2_PORT, KEYPAD_u8COL2, 1);

	GPIO_vidSetPinValue(KEYPAD_u8COL3_PORT, KEYPAD_u8COL3, 1);
	
	GPIO_vidSetPinValue(KEYPAD_u8COL4_PORT, KEYPAD_u8COL4, 1);

	Button = KeyPad_u8CheckRow(0);
	if (Button != '\0'){
		if(i == 1){
			return '\0';
		}
		i=1;
		return Button;
	}
	/*Apply sequence 1 */
	
	GPIO_vidSetPinValue(KEYPAD_u8COL1_PORT, KEYPAD_u8COL1, 1);

	GPIO_vidSetPinValue(KEYPAD_u8COL2_PORT, KEYPAD_u8COL2, 0);

	GPIO_vidSetPinValue(KEYPAD_u8COL3_PORT, KEYPAD_u8COL3, 1);
	
	GPIO_vidSetPinValue(KEYPAD_u8COL4_PORT, KEYPAD_u8COL4, 1);

	Button = KeyPad_u8CheckRow(1);
	if (Button != '\0'){
		if(i == 1){
			return '\0';
		}
		i=1;
		return Button;
	}

	/*Apply sequence 2 */

	GPIO_vidSetPinValue(KEYPAD_u8COL1_PORT, KEYPAD_u8COL1, 1);

	GPIO_vidSetPinValue(KEYPAD_u8COL2_PORT, KEYPAD_u8COL2, 1);

	GPIO_vidSetPinValue(KEYPAD_u8COL3_PORT, KEYPAD_u8COL3, 0);
	
	GPIO_vidSetPinValue(KEYPAD_u8COL4_PORT, KEYPAD_u8COL4, 1);

	Button = KeyPad_u8CheckRow(2);
	if (Button != '\0'){
		if(i == 1){
			return '\0';
		}
		i=1;
		return Button;
	}

	/*Apply sequence 3 */
	
	GPIO_vidSetPinValue(KEYPAD_u8COL1_PORT, KEYPAD_u8COL1, 1);

	GPIO_vidSetPinValue(KEYPAD_u8COL2_PORT, KEYPAD_u8COL2, 1);
	
	GPIO_vidSetPinValue(KEYPAD_u8COL3_PORT, KEYPAD_u8COL3, 1);

	GPIO_vidSetPinValue(KEYPAD_u8COL4_PORT, KEYPAD_u8COL4, 0);

	Button = KeyPad_u8CheckRow(3);
	
	if (Button != '\0'){
		if(i == 1){
			return '\0';
		}
		i=1;
		return Button;
	}
	i=0;
	return Button;
}


static uint8_t KeyPad_u8CheckRow(uint8_t COL)
{
	if (GPIO_u8GetPinValue(KEYPAD_u8ROW1_PORT, KEYPAD_u8ROW1) == 0)
	{
		switch (COL)
		{
		case 0:
			return KEYPAD_u8R1C1;
			

		case 1:
			return KEYPAD_u8R1C2;
			

		case 2:
			return KEYPAD_u8R1C3;
			

		case 3:
			return KEYPAD_u8R1C4;
			
		}
	}
	if (GPIO_u8GetPinValue(KEYPAD_u8ROW2_PORT, KEYPAD_u8ROW2) == 0)
	{
		switch (COL)
		{
		case 0:
			return KEYPAD_u8R2C1;
			

		case 1:
			return KEYPAD_u8R2C2;
			

		case 2:
			return KEYPAD_u8R2C3;
			

		case 3:
			return KEYPAD_u8R2C4;
			
		}
	}
	if (GPIO_u8GetPinValue(KEYPAD_u8ROW3_PORT, KEYPAD_u8ROW3) == 0)
	{
		switch (COL)
		{
		case 0:
			return KEYPAD_u8R3C1;
			

		case 1:
			return KEYPAD_u8R3C2;
			

		case 2:
			return KEYPAD_u8R3C3;
			

		case 3:
			return KEYPAD_u8R3C4;
			
		}
	}
	if (GPIO_u8GetPinValue(KEYPAD_u8ROW4_PORT, KEYPAD_u8ROW4) == 0)
	{
		switch (COL)
		{
		case 0:
			return KEYPAD_u8R4C1;
			

		case 1:
			return KEYPAD_u8R4C2;
			

		case 2:
			return KEYPAD_u8R4C3;
			

		case 3:
			return KEYPAD_u8R4C4;
			
		}
	}

	return '\0';
}
