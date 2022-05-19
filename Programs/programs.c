/*
    author : Mina Mounir Farid
*/
#include "programs.h"
#include "tm4c123.h"
void External_Button_Init()
{
    GPIO_DIO_vidPinInit(GPIO_PORTE , 0);
    GPIO_vidSetPinDirection(GPIO_PORTE, 0, 0); //input
    GPIO_vidSetPinPullUpRes(GPIO_PORTE, 0, 1);//activate pull up resistor of pin

}

void Buzzer_Init()
{
    GPIO_DIO_vidPinInit(GPIO_PORTB , 3);
    GPIO_vidSetPinDirection(GPIO_PORTB, 3, 1); //output

}

void SW3_Interrupt()
{
    systick_Disable();
     //make the timer stop during pause
   SET_BIT(GPIO_PORTE_IS_R,0);
   while(isCooking && ! GPIO_u8GetPinValue(GPIO_PORTE , 0) );   //if in cooking state and door is open  
      systick_Enable();   
     CLEAR_BIT(GPIO_PORTE_IS_R,0);
}
void SW1_Interrupt()
{
    systick_Disable(); //make the timer stop during pause
    while(1) //pause loop
    {

		   SET_BIT(GPIO_PORTF_IS_R,4);
           GPIO_PORTF_DATA_R ^= 0x0E; //blinking leds
           systick_vidDelay(500);
         if(GPIO_u8GetPinValue(GPIO_PORTF,4) == Low) //if SW1 is pressed again
        {
			CLEAR_BIT(GPIO_PORTF_IS_R,4);
            NVIC_SystemReset(); //terminate cooking process
         }
         if(GPIO_u8GetPinValue(GPIO_PORTF,0) == Low && GPIO_u8GetPinValue(GPIO_PORTE,0) == High )
          {//if SW2 is pressed again resume cooking and door is closed
           CLEAR_BIT(GPIO_PORTF_IS_R,4);
			break;
		 }
    }
    systick_Enable();  //enable the dimer because the pause period has ended 
}
void Program_A()
{
	LCD_vidClearScreen();
     LCD_vidWriteString("Popcorn", strlen("Popcorn")); //display popcorn on LCD
     while(Oven_Ready() == 0) ; //wait until oven is ready (door closed and SW2 pressed)
     isCooking = 1 ;
     Turn_on_LEDs() ;
     LCD_vidCountDown(100,1); //wait for 1 minute (input entered in format (1:00) which is the standard form
                                            
	 Program_Finish() ; //finsihing  program for microwave
}

void Program_B_or_C(uint8_t key) //this program works for choices B or C
{
				
        uint8_t defrost_rate ; //in minutes per kilogram
        uint16_t kilograms = '\0'; //the button entered represents the number of kilograms
        LCD_vidClearScreen();
Repeat:  if(key == 'B') //in case keypad button 'B' is pressed ,
        {
            LCD_vidWriteString("Beef Weight?" , strlen("Beef Weight?") ); //then display the beef weight
            defrost_rate = BEEF_DEFROST_RATE; //set the defrost_rate to be 0.5
        }
        else if(key == 'C') //in case keypad button 'C' is pressed ,
        {
            LCD_vidWriteString("Chicken Weight?" , strlen("Chicken Weight?")); //then display the beef weight
            defrost_rate =  CHICKEN_DEFROST_RATE ; //set the defrost_rate to be 0.2
         }       
		while(kilograms =='\0'){ //wait until user presses a valid button
			kilograms = KEYPAD_u8GetButton();
		}
		// only read 1 character as the valid number of kilograms are from 1 till 9 , print Err if this character is incorrect 
        if( kilograms >= '1' && kilograms <='9' ) 
	{
           //any integer between 1 and 9 is accepted
            LCD_vidClearScreen();
            LCD_vidWriteChar(kilograms) ; //write the number of kilograms entered
            systick_vidDelay(2000); //2 seconds delay
            while(Oven_Ready() == 0) ; //must wait until door is closed and SW2 is pressed
            isCooking = 1;
            Turn_on_LEDs() ;
            LCD_vidClearScreen();
            LCD_vidCountDown(defrost_rate * (kilograms-'0'),0); //time to wait in seconds
	}
        else{ //invalid number of kilograms
            LCD_vidClearScreen();
            LCD_vidWriteString("Err", strlen("Err")  );
            systick_vidDelay(2000);
            kilograms = '\0';
            LCD_vidClearScreen();
            goto Repeat ;
        }
		Program_Finish() ; //finsihing  program for microwave
}

void Program_D() //for other kinds of food
{
	
       uint16_t  timer  ;
	   LCD_vidClearScreen();
        LCD_vidWriteString("Cooking time?", strlen("Cooking time?") );
		LCD_vidClearScreen();
    do{
		LCD_vidClearScreen();
		LCD_vidWriteString("(1 till 30:00)",strlen("(1 till 30:00)"));
        timer = LCD_u16TakeInput() ; //user must enter a valid time (1 till 30:00)
     }while(timer == 0);
     if(GPIO_u8GetPinValue(GPIO_PORTF,4) == Low) 
        LCD_vidClearScreen(); //switch 1 pressed to clear LCD
     while(Oven_Ready() == 0) ; //wait until door is closed and switch 2 is pressed then the LEDs are on and the countdown starts
        isCooking = 1 ;
        Turn_on_LEDs() ;
        LCD_vidCountDown(timer,1)  ; //time is entered in standard form
        Program_Finish() ; //finishing  program for microwave
}

void Program_Finish() //terminating program of the microwave. this is always executed after programs A or B or C or D
{
    uint8_t i;
    isCooking = 0;
    LCD_vidClearScreen(); //clear the LCD
	LCD_vidWriteString("Done",4);
    Turn_off_LEDs(); //turn off the LEDs
    for(i = 0 ; i < 3 ; i++ )
        {
            Turn_on_LEDs(); //turning the LEDs on and off should make them blink
	        tuneBuzzer(); //sound the buzzer and wait for 1 second between blinking periods
            Turn_off_LEDs();
            tuneBuzzer(); //sound the buzzer and wait for 1 second between blinking periods
         }
				LCD_vidClearScreen(); //clear the LCD
}
uint8_t Oven_Ready() //to check if door is closed and SW2 is pressed(cooking conditions)
{
    return ( GPIO_u8GetPinValue(GPIO_PORTE, 0) &&  !GPIO_u8GetPinValue(GPIO_PORTF, 0) ) ; //external switch connected to port E pin 0 and SW2 (switch 3 being up and switch 2 being down)
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
	for(i = 0; i < 500;i++){
		GPIO_vidSetPinValue(GPIO_PORTB,3,1);
		systick_vidDelay(1);
		GPIO_vidSetPinValue(GPIO_PORTB,3,0);
		systick_vidDelay(1);
	}
}
