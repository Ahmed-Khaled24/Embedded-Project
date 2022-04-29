#ifndef LCD_COMMANDS
#define LCD_COMMANDS


// NOTICE: Home position is the first char in the first row 

//------------------------------ CLEAR DISPLAY [Delay: 1.64ms] --------------------------------------------------------------------------------

#define ClearScreen                             0x01            // Clear the screen and return the cursor to home position.

//------------------------------ CURSOR HOME [Delay: 1.64ms] ----------------------------------------------------------------------------------

#define ResetCursor                             0x02            // Return cursor to home position without clearing the screen.

//------------------------------ ENTRY MODE SET [Delay: 40 micro second] ----------------------------------------------------------------------

#define SetCursorGoRight                        0x06            // Set cursor to go one position right after every write operation.
#define SetCursorGoLeft                         0x04            // Set cursor to go one position left after every write operation.
#define SetDisplayGoLeft                        0x07            // Set display go one position left after every write operation.
#define SetDisplayGoRight                       0x05            // Set display go one position right after every write operation.

//------------------------------ DISPLAY ON/OFF [Delay: 40 micro second] ----------------------------------------------------------------------

#define SetDisplayOnCursorOff                   0x0C            // Set display on and cursor off.
#define SetDisplayOnCursorOnNoBlinking          0x0E            // Set display on and cursor on and the cursor doesn't blinking.
#define SetDisplayOnCursorOnBlinking            0x0F            // Set display on and cursor on and the cursor blinking.
#define SetDisplayOff                           0x08            // Turn off display but the content remain unchanged in case turn on again.

//------------------------------ CURSOR AND DISPLAY SHIFT [Delay: 40 micro second] ------------------------------------------------------------

#define ShiftCursorLeft                         0x10            // Shift cursor one position left.
#define ShiftCursorRight                        0x14            // Shift cursor one position right.
#define ShiftDisplayLeft                        0x18            // Shift display one position left.
#define ShiftDisplayRight                       0x1C            // Shift display one position right.
#define GoToSecondLine                          0xC0            // Go to the second line.

//------------------------------ FUNCTION SET [Delay: 40 micro second] ------------------------------------------------------------------------

#define Set_8bit_5x7_1Line                      0x30            // Set the Lcd operate on 8-bit mode, 5x7 font, and 1 Line display
#define Set_8bit_5x10_1Line                     0x34            // Set the Lcd operate on 8-bit mode, 5x10 font, and 1 Line display
#define Set_8bit_5x7_2Line                      0x38            // Set the Lcd operate on 8-bit mode, 5x7 font, and 2 Line display





#endif