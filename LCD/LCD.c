#include "LCD.h"
#include "LCD-Commands.h"
#include "../GPIO/GPIO_driver.h"
#include "../Systick/Systick.h"
#include "../Keypad/Keypad_interface.h"

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

int MinToTimerStandard(double number) { // this function will be used in the countdown function
	// It converts from minutes only to minutes and second form to be put in countdown function 
	// this function's parameter must be in minutes, ex: 4.5 minutes to outpit 430 to be put in countdown method

	int min = number; // taking the integer part
	double sec = (number - min) * 0.6; // the part after the decimal point  getting it in second then dividing by a 100
	double result = (min + sec) * 100; // adding the integer and the decimal part then multiplying by a 100 to get the standard form 
									  // needed in the countdown function
	return result;
}



void LCD_vidCountDown(double timer) {
// you have to input the time as minutesSeconds, ex: 1234 is 12 minutes 34 seconds , 123 is 1 minutes 23 seconds
// or as a minutes only format as its converted by the MinToTimerStandard function ex:4.5 becomes 430

	if ((timer - (int)timer) != 0) {
		timer = MinToTimerStandard(timer);
	}


	unsigned int min = timer / 100, sec = (int)timer % 100; 		// divide the lower 2 digits to seconds and upper 2 digits to minutes
	char stringMin[20], StringSec[20]; 					// create the strings that are going to be outputted on the LCD
	itoa(min, stringMin, 10); 						// coverts the current minutes to string to be written on LCD
	itoa(sec, StringSec, 10); 						// coverts the current seconds to string to be written on LCD
	while (atoi(stringMin) >= 0) { 						// keeps looping till the minutes reach 0
		while (atoi(StringSec) >= 1) { 					// keeps looping till the seconds reach 0
			itoa(min, stringMin, 10);
			LCD_vidWriteString(stringMin, strlen(stringMin));
			LCD_vidWriteChar(':');
			itoa(sec, StringSec, 10);
			LCD_vidWriteString(StringSec, strlen(StringSec));
			systic_vidDelay(1000); 					//wait a second to decrement a unit digit in the seconds
			LCD_vidSendCommand(ClearScreen);
			sec--; 
		}
		sec = 59;							// set the seconds to a whole minute
		min--;
		itoa(min, stringMin, 10);					// re initialize the minutes and seconds
		itoa(sec, StringSec, 10);
	}
}

// These two functions to implement TakeInput().
// 1.
void printTimer(char* timer) {
	// Loop 4 times as the timer consist of 4 digits.
	for (uint8_t i = 0; i < 4; i++) {
		if (i == 2)   LCD_vidWriteChar(':');
		LCD_vidWriteChar(timer[i]);
	}
}
// 2. 
void shiftTimerLeft(char* timer) {
	for (uint8_t i = 1; i < 4; i++) {
		timer[i - 1] = timer[i];
	}
}

uint16_t LCD_u16TakeInput(void) {
/* 
	 This function takes 4-digit (numbers) input from the user for example(1, 2, 3, 4)
	 Important note(1): user must enter the numbers from left to right 1 -> 2 -> 3 -> 4 
	 this produces the number 1234 which is 12 minutes and 34 seconds.
	 Important note(2): the 4-digin input must be less than or equal 3000, if bigger 
	 the function returns -1.
*/
	
	// Create a timer.
	char timer[4] = {'0', '0', '0', '0'};

	// Clear the screen to start take input from the user.
	LCD_vidClearScreen();
	
	// Print the current status of the timer to the screen [ 00:00 ].
	printTimer(timer);

	// Loop 4 times to read from the keypad.
	for (uint8_t i = 0; i < 4; i++) {
		uint8_t pressedButton = '\0';
		
		// Wait till the user press a button
		while (pressedButton == '\0') {
			pressedButton = KEYPAD_u8GetButton();
		}

		// Convert pressedButton to char to print on the screen, then add it to the right most cell in the timer.
		char currentInput = pressedButton + '0';
		timer[3] = currentInput;

		// Print the timer with the new input on the LCD. 
		// For example the user pressed 1 >>>> screen shows [ 00:01 ]
		LCD_vidClearScreen();
		printTimer(timer);

		// Shift the timer digits left to take the next input except for the last iteration.
		if (i < 3)
			shiftTimerLeft(timer);

		// Wait for 1 second for a new reaction from the user.
		systic_vidDelay(1000);
	}

	// Extract the return value from the timer array.
	uint16_t timerInt = 0;
	for (uint8_t i = 0; i < 4; i++) {
		uint16_t currentDigit = timer[i] - '0';
		if (i == 0)
			timerInt += (currentDigit * 1000);
		else if (i == 1)
			timerInt += (currentDigit * 100);
		else if (i == 2)
			timerInt += (currentDigit * 10);
		else if (i == 3)
			timerInt += currentDigit;	
	}
	
	if(timerInt >= 1 && timerInt <= 3000)
		return timerInt;
	else 
		return 0;
}








