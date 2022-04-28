#include<LCD.h>
#include<LCD-Commands.h>
#include<../GPIO/GPIO_driver.h>
#include<../Systick/Systick.h>


void LCD_vidSendCommand(unsigned char command) {
	// If the command is ClearScreen or ResetCursor it will take 1.64ms to apply the command so,
	// a delay of 2ms should be applied.
	uint8_t DelayToApplyCommand;
	if (command == 0x01 || command == 0x02)
		DelayToApplyCommand = 2;
	else 
		DelayToApplyCommand = 1;

	// Select to write on command register
	GPIO_vidSetPinValue(GPIO_PORTB, 0, High);

	// The next step is to apply the command bits to data bits D0->D7 that connected to port-D
	GPIO_vidSetPortValue(GPIO_PORTD, command);

	// Then enable write on LCD command register
	GPIO_vidSetPinValue(GPIO_PORTB, 2, High);
	// Delay to apply command
	systic_vidDelay(DelayToApplyCommand);
	// Disable the write on LCD command register
	GPIO_vidSetPinValue(GPIO_PORTB, 2, Low);
}

void LCD_vidScreenInit(void) {
	// Setup tiva pins
	// 1. use port-D for 8-bit data.
	GPIO_DIO_vidPortInit(GPIO_PORTD);
	GPIO_vidSetPortDirection(GPIO_PORTD, 0xFF);

	// 2. use pins B0, B1, and B2 
	//             RS, RW, and E
	GPIO_DIO_vidPinInit(GPIO_PORTB, 0);
	GPIO_DIO_vidPinInit(GPIO_PORTB, 1);
	GPIO_DIO_vidPinInit(GPIO_PORTB, 2);
	GPIO_vidSetPinDirection(GPIO_PORTB, 0, High);
	GPIO_vidSetPinDirection(GPIO_PORTB, 1, High);
	GPIO_vidSetPinDirection(GPIO_PORTB, 2, High);


	// Setup the LCD according to the datasheet
	systic_vidDelay(15);
	LCD_vidSendCommand(Set_8bit_5x7_1Line);
	systic_vidDelay(5);
	LCD_vidSendCommand(Set_8bit_5x7_1Line);
	systic_vidDelay(1);
	LCD_vidSendCommand(Set_8bit_5x7_1Line);
	// Additional commands (custom initialization)
	LCD_vidSendCommand(ClearScreen);
	LCD_vidSendCommand(SetDisplayOnCursorOnBlinking);
	LCD_vidSendCommand(SetCursorGoRight);
	LCD_vidSendCommand(Set_8bit_5x7_1Line);
}

void LCD_vidClearScreen(void) {
	LCD_vidSendCommand(ClearScreen);
}


