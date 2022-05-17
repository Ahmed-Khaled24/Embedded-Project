/*
    author : Mina Mounir Farid
*/
#include "programs.h"
void Program_Interrupt() 
{
    while(1) //pause loop
    {
           GPIO_PORTF_DATA_R ^= 0x0E; //blinking leds
           systick_vidDelay(2000);
         if(GPIO_u8GetPinValue(GPIO_PORTF,4) == Low) //if SW1 is pressed again
        {
            NVIC_SystemReset(); //terminate cooking process
         }
         if(GPIO_u8GetPinValue(GPIO_PORTF,0) == Low && GPIO_u8GetPinValue(GPIO_PORTE,0) == High ) //if SW2 is pressed again resume cooking and door is closed 
            break;
    }
}
void Program_A()
{
     LCD_vidWriteString("Popcorn", strlen("Popcorn")); //display popcorn on LCD
     while(Oven_Ready() == 0) ; //wait until oven is ready (door closed and SW2 pressed)
     Turn_on_LEDs() ;
     LCD_vidCountDown(100); //wait for 1 minute (input entered in format (1:00)
}

void Program_B_or_C(uint8_t key) //this program works for choices B or C
{
        double defrost_rate ; //in minutes per kilogram
        uint16_t kilograms ; //in kilograms
Repeat:  if(key == KEYPAD_u8R2C4) //in case keypad button 'B' is pressed ,
        {
            LCD_vidWriteString("Beef Weight?" , strlen("Beef Weight") ); //then display the beef weight
            defrost_rate = BEEF_DEFROST_RATE; //set the defrost_rate to be 0.5
        }
        else if(key == KEYPAD_u8R2C4) //in case keypad button 'C' is pressed ,
        {
            LCD_vidWriteString("Chicken Weight?" , strlen("Beef Weight")); //then display the beef weight
            defrost_rate =  CHICKEN_DEFROST_RATE ; //set the defrost_rate to be 0.2
         }
         kilograms = KEYPAD_u8GetButton(); //the button entered represents the number of kilograms
        if( kilograms >= 1 && kilograms <=9 )
	{
           //any integer between 1 and 9 is accepted
            LCD_vidClearScreen();
            LCD_vidWriteChar(kilograms) ; //write the number of kilograms entered
            systick_vidDelay(2000); //2 seconds delay
            while(Oven_Ready() == 0) ; //must wait until door is closed and SW2 is pressed
            Turn_on_LEDs() ;
            LCD_vidClearScreen();
            LCD_vidCountDown(defrost_rate * kilograms); //time to wait in minutes
	}
        else{ //invalid number of kilograms
            LCD_vidClearScreen();
            LCD_vidWriteString("Err", strlen("Err")  );
            systick_vidDelay(2000);
            goto Repeat ;
        }
}

void Program_D() //for other kinds of food
{
     uint16_t  timer  ;
     LCD_vidWriteString("Cooking time?", strlen("Cooking time?") );
    do{
        timer = LCD_u16TakeInput() ; //user must enter a valid time (1 till 30:00)
     }while(timer == 0);
     if(GPIO_u8GetPinValue(GPIO_PORTF,4) == Low) //switch 1 pressed to clear LCD
        LCD_vidClearScreen();
     while(Oven_Ready() == 0) ; //wait until door is closed switch 2 is pressed then the LEDs are on and the countdown starts
        Turn_on_LEDs() ;
        LCD_vidCountDown(timer)  ;

}

void Program_Finish() //terminating program of the microwave. this is always executed after programs A or B or C or D
{
    uint8_t i;
    LCD_vidClearScreen(); //clear the LCD
    Turn_off_LEDs(); //turn off the LEDs
    for(i = 0 ; i < 3 ; i++ )
        {
            Turn_on_LEDs(); //turning the LEDs on and off should make them blink
            Turn_off_LEDs();
            tuneBuzzer(); //sound the buzzer and wait for 1 second between blinking periods
         }
    

}
uint8_t Oven_Ready() //to check if door is closed and SW2 is pressed(cooking conditions)
{
    return ( GPIO_u8GetPinValue(GPIO_PORTE, 0) &&  GPIO_u8GetPinValue(GPIO_PORTF, 0) ) ; //external switch connected to port E pin 0 and SW2
}

void Turn_on_LEDs() //turn on the three LEDs
{
   uint8_t i;
   for(i = 1 ; i<= 3 ; i++ )
     GPIO_vidSetPinValue(GPIO_PORTF ,i , High) ;
}

void Turn_off_LEDs() //turn off the Three LEDs
{
   uint8_t i;
   for(i = 1 ; i<= 3 ; i++ )
     GPIO_vidSetPinValue(GPIO_PORTF ,i , Low) ;
}
void tuneBuzzer(void) //buzzer function explained in the header
{

	uint16_t i;
	for(i = 0; i < 1000;i++){
		GPIO_vidSetPinValue(GPIO_PORTB,3,1);
		systick_vidDelay(1);
		GPIO_vidSetPinValue(GPIO_PORTB,3,0);
		systick_vidDelay(1);
	}
}
