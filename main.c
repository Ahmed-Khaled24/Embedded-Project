/*
    author : Mina Mounir Farid
*/

#include "programs.h"

int main()
{
    uint8_t i;
    systick_vidInit() ;
    LCD_vidScreenInit();
    KEYPAD_init();
    for(i = GPIO_PORTA ; i <= GPIO_PORTF ; i++ )
            GPIO_DIO_vidPortInit(i);
    while(1)
    {
        switch(KEYPAD_u8GetButton())
        {
            case KEYPAD_u8R1C4:
                    Program_A("Popcorn") ;
                    break;
            case KEYPAD_u8R2C4:
                    Program_B_or_C("Beef" , KEYPAD_u8R2C4) ;
                    break;
            case KEYPAD_u8R3C4:
                    Program_B_or_C("Chicken" ,KEYPAD_u8R3C4) ;
                    break;
            case  KEYPAD_u8R4C4:
                    Program_D() ;
                    break;
            default:
                    LCD_vidWriteString("Error", sizeof("Popcorn"));
                    LCD_vidClearScreen();
        }
        Program_Finish() ;
    }

    return 0;
}


