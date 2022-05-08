/*
    author : Mina Mounir Farid
*/

#include "Programs/programs.h"

int main()
{
    uint8_t i; //loop counter
    systick_vidInit() ; //initialize the systick timer ;
    LCD_vidScreenInit(); //initialize the LCD
    KEYPAD_init(); //intialize the keypad
    for(i = GPIO_PORTA ; i <= GPIO_PORTF ; i++ ) //activate all ports
            GPIO_DIO_vidPortInit(i);
    while(1) //program active all the time
    {
        switch(KEYPAD_u8GetButton()) //keypad input from the user to choose which program to execute
        {
            case KEYPAD_u8R1C4: //if user presses on key A then  make microwave execute  Program_A for popcorn
                    Program_A("Popcorn") ;
                    break; //break statement prevents executing more than 1 program in a single run
            case KEYPAD_u8R2C4: //if user presses on key B then  make microwave execute  Program_B for beef
                    Program_B_or_C(KEYPAD_u8R2C4) ;
                    break;
            case KEYPAD_u8R3C4: //if user presses on key C then  make microwave execute  Program_C for chicken
                    Program_B_or_C(KEYPAD_u8R3C4) ;
                    break;
            case  KEYPAD_u8R4C4: //if user presses on key D then  make microwave execute  Program_D for other food
                    Program_D() ;
                    break;
            default:
                    LCD_vidWriteString("Error", strlen("Error")); //otherwise , LCD displays Error and then it clears
                    systic_vidDelay(2000); //wait for 2 seconds
                    LCD_vidClearScreen();
                    continue ; //to skip entering the finishing program
        }
        Program_Finish() ; //finsihing  program for microwave
    }

    return 0;
}


