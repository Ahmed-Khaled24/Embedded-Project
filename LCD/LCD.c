#include "LCD.h"
#include "LCD-Commands.h"
#include "GPIO_driver.h"
#include "Systick.h"


// Define RS as PB0 and E as PB1
#define RS 0
#define E  1


void LCD_vidSendCommand(unsigned char command) {
	// Select to write on command register [RS = 0]
	// According to datasheet time digram a delay of 40ns should be applied before set E = 1.
	GPIO_vidSetPinValue(GPIO_PORTB, RS, Low);
	systic_vid1MicroDelay();

	// Apply the command bits to data bits D0->D7 of the LCD that connected to port-D
	// According to datasheet time digram a delay of 80ns should be applied before the falling edge of E.
	GPIO_vidSetPortValue(GPIO_PORTD, command);
	systic_vid1MicroDelay() ;

	// Create falling edge for the write operation to start
	// According to datasheet time digram the pulse width must be greater than 230ns
	// [E] --> Low to High
	GPIO_vidSetPinValue(GPIO_PORTB, E, High);
	systic_vid1MicroDelay();
	// [E] --> High to Low
	GPIO_vidSetPinValue(GPIO_PORTB, E, Low);
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

	// 2. use pins B0, B1
	//             RS, E
	GPIO_DIO_vidPinInit(GPIO_PORTB, RS);
	GPIO_DIO_vidPinInit(GPIO_PORTB, E);
	GPIO_vidSetPinDirection(GPIO_PORTB, RS, High);
	GPIO_vidSetPinDirection(GPIO_PORTB, E, High);


	// Setup the LCD.
	LCD_vidSendCommand(Set_8bit_5x7_2Line);
	LCD_vidSendCommand(ClearScreen);
	LCD_vidSendCommand(SetCursorGoRight);
	LCD_vidSendCommand(SetDisplayOnCursorOnBlinking);

}

void LCD_vidClearScreen(void) {
	LCD_vidSendCommand(ClearScreen);
}

void LCD_vidWriteChar(char c) {
	//set RS for data registers (Read/write) and wait for delay
	GPIO_vidSetPinValue(GPIO_PORTB, RS, High);
	systic_vid1MicroDelay();

	//add character bits inputted in the pins D0 -> D7 and wait for delay
	GPIO_vidSetPortValue(GPIO_PORTD, c);
	systic_vid1MicroDelay();

	// Create falling edge for the write operation to start
    // According to datasheet time digram the pulse width must be greater than 230ns
    // [E] --> Low to High
	GPIO_vidSetPinValue(GPIO_PORTB, E, High);
	systic_vid1MicroDelay();
	// [E] --> High to Low
	GPIO_vidSetPinValue(GPIO_PORTB, E, Low);
	systic_vid1MicroDelay();


}
void LCD_vidWriteString(char* string, unsigned int stringSize) {

	for (int i = 0; i < stringSize; i++) {
		if (i == 16) LCD_vidSendCommand(GoToSecondLine);
		LCD_vidWriteChar(string[i]);
	}


}

void LCD_vidCountDown(unsigned int timer) {
	unsigned int min = timer / 100, sec = timer % 100;
	char string1[20], string2[20];
	itoa(min, string1, 10);
	itoa(sec, string2, 10);
	while (atoi(string1) >= 0) {
		while (atoi(string2) >= 1) {
			itoa(min, string1, 10);
			LCD_vidWriteString(string1, strlen(string1));

			LCD_vidWriteChar(':');
			itoa(sec, string2, 10);
			LCD_vidWriteString(string2, strlen(string2));
			delay(1000);
			LCD_vidSendCommand(ClearScreen);
			sec--;
		}

		sec = 59;
		min--;
		itoa(min, string1, 10);
		itoa(sec, string2, 10);

	}

}


