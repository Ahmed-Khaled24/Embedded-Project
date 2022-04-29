#include<LCD.h>
#include<LCD-Commands.h>
#include<../GPIO/GPIO_driver.h>
#include<../Systick/Systick.h>


void LCD_vidSendCommand(unsigned char command) {
	// Select to write on command register [RS = 0] 
	// According to datasheet time digram a delay of 40ns should be applied before set E = 1.
	GPIO_vidSetPinValue(GPIO_PORTB, 0, Low);
	systic_vid1MicroDelay();

	// Apply the command bits to data bits D0->D7 of the LCD that connected to port-D
	// According to datasheet time digram a delay of 80ns should be applied before the falling edge of E.
	GPIO_vidSetPortValue(GPIO_PORTD, command);
	systic_vid1MicroDelay()

	// Create falling edge for the write operation to start
	// According to datasheet time digram the pulse width must be greater than 230ns
	// [E] --> Low to High
	GPIO_vidSetPinValue(GPIO_PORTB, 2, High);
	systic_vid1MicroDelay();
	// [E] --> High to Low
	GPIO_vidSetPinValue(GPIO_PORTB, 2, Low);
	systic_vid1MicroDelay();

	// If the command is ClearScreen or ResetCursor it will take 1.64ms to apply the command so,
	// a delay of 2ms should be applied, and for any other command it will take 40 microsecond.
	if (command == ClearScreen || command == ResetCursor)
		systic_vidDelay(2);
	else
		systic_vid1msDelay();
}

void LCD_vidScreenInit(void) {

	// Delay 15ms for the LCD to work properly [Datasheet instruction]
	systic_vidDelay(15);

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
	GPIO_vidSetPinValue(GPIO_PORTB, 1, Low);


	// Setup the LCD.
	LCD_vidSendCommand(Set_8bit_5x7_2Line);
	LCD_vidSendCommand(ClearScreen);
	LCD_vidSendCommand(SetCursorGoRight);
	LCD_vidSendCommand(SetDisplayOnCursorOnBlinking);

}

void LCD_vidClearScreen(void) {
	LCD_vidSendCommand(ClearScreen);
}

void void LCD_vidWriteChar(unsigned char c) { 
	//set RS for data registers (Read/write) and wait for delay
	GPIO_vidSetPinValue(PORTB, 0, High);
	systic_vid1MicroDelay();

	//add character bits inputted in the pins D0 -> D7 and wait for delay
	GPIO_vidSetPortValue(PORTD, c);
	systic_vid1MicroDelay();

	// Create falling edge for the write operation to start
    // According to datasheet time digram the pulse width must be greater than 230ns
    // [E] --> Low to High
	GPIO_vidSetPinValue(GPIO_PORTB, 2, High);
	systic_vid1MicroDelay();
	// [E] --> High to Low
	GPIO_vidSetPinValue(GPIO_PORTB, 2, Low);
	systic_vid1MicroDelay();

	LCD_vidSendCommand(SetCursorGoRight);

}


