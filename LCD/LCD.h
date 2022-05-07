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
void LCD_vidWriteString(char* string, unsigned int stringSize);

// Countdown timer 
void LCD_vidCountDown(unsigned int timer);

 


#endif