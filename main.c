/*
    author : Mina Mounir Farid
*/

#include "Programs/programs.h"

int main()
{
    uint8_t choice;
		uint8_t i =0;//flag for printing begining word
    systick_vidInit() ; //initialize the systick timer ;
		GPIO_DIO_vidPortInit(GPIO_PORTF); //initialize portF
		GPIO_vidSetPortDirection(GPIO_PORTF,0xE);
		GPIO_vidSetPortPullUpRes(GPIO_PORTF,0x11);
    LCD_vidScreenInit(); //initialize the LCD
    KEYPAD_init(); //initialize the keypad
    Interrupt_init(4); //initialize the interrupt
    GPIOF_setHandler(Program_Interrupt); //set the interrupt handler to Program_Interrupt function
    External_Button_Init(); //initialize the external button
    Buzzer_Init(); //intialize the buzzer
		
    while(1) //program active all the time
    {
			
        if(i == 0)LCD_vidWriteString("Choose program(A-B-C-D)",strlen("Choose program(A-B-C-D)"));
				i=1;
      	choice = KEYPAD_u8GetButton();
        switch(choice) //keypad input from the user to choose which program to execute
        {
            case 'A': //if user presses on key A then  make microwave execute  Program_A for popcorn
							i=0;
                 Program_A();
                  break; //break statement prevents executing more than 1 program in a single run
            case 'B': //if user presses on key B then  make microwave execute  Program_B for beef
							i=0;
                    Program_B_or_C('B') ;
                    break;
            case 'C': //if user presses on key C then  make microwave execute  Program_C for chicken
							i=0;
                    Program_B_or_C('C') ;
                    break;
            case  'D': //if user presses on key D then  make microwave execute  Program_D for other food
							i=0;
                    Program_D() ;
                    break;
						
        }       
    }
    
}
