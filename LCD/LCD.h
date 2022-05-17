#ifndef LCD_DRIVER
#define LCD_DRIVER



#include<stdint.h>

// Send command to the LCD
void LCD_vidSendCommand(uint8_t command);

// Initialize the LCD
void LCD_vidScreenInit(void);

// Clear the screen 
void LCD_vidClearScreen(void);

// Write a character on the LCD
void LCD_vidWriteChar(unsigned char c);

// Write a string on the LCD
void LCD_vidWriteString(unsigned char* string, uint8_t stringSize);

// Countdown timer 
void LCD_vidCountDown(int16_t timer, uint8_t isStandardForm);

// Take 4-digit input from the user and return the input.
uint16_t LCD_u16TakeInput(void);

// Cursor go to the provided location.
void goToRowColumn(uint8_t row, uint8_t column);


#endif
