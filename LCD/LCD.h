#ifndef LCD_DRIVER
#define LCD_DRIVER



#include<stdint.h>

// Send command to the LCD
void LCD_vidSendCommand(unsigned char command);

// Initialize the LCD
void LCD_vidScreenInit(void);

// Clear the screen 
void LCD_vidClearScreen(void);

// Write a character on the LCD
void LCD_vidWriteChar(char c);

// Write a string on the LCD
void LCD_vidWriteString(char* string, uint8_t stringSize);

// Countdown timer 
void LCD_vidCountDown(double timer);

// Take 4-digit input from the user and return the input.
uint16_t LCD_u16TakeInput(void);


#endif
