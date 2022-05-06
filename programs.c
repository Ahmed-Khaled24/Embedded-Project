/*
    author : Mina Mounir Farid
*/


#include "programs.h"

void Program_A(char* str)
{
     LCD_vidWriteString(str, strlen(str)+1);
     while(Oven_Ready() == 0) ;
     Turn_on_LEDs() ;
     systic_vidDelay(60*1000)  //1 minute delay
     Turn_off_LEDs() ;
     //LCD countdown function is not complete yet
     LCD_vidClearScreen();
}

void Program_B_or_C(char* str , uint8_t key)
{
        double defrost_rate ;
        uint8_t kilos ;
        LCD_vidWriteString(str, strlen(str) +1);
Repeat:  if(strcmp(str,"Beef") == 0)
        {
            LCD_vidWriteString("Beef Weight?" , strlen("Beef Weight")+1 );
            defrost_rate = BEEF_DEFROST_RATE;
        }
        else if(strcmp(str , "Chicken") == 0)
        {
            LCD_vidWriteString("Chicken Weight?" , strlen("Beef Weight")+1 );
            defrost_rate =  CHICKEN_DEFROST_RATE ;
         }
          kilos = KEYPAD_u8GetButton();
        switch(kilos)
        {
        case 1 ... 9:
            LCD_vidClearScreen();
            LCD_vidWriteChar(kilos) ;
            systic_vidDelay(2000); //2 seconds delay
            while(Oven_Ready() == 0) ;
            Turn_on_LEDs() ;
            systic_vidDelay(defrost rate * kilos * 1000 );
            Turn_off_LEDs() ;
            LCD_vidClearScreen();
             break;
        default:
            LCD_vidClearScreen();
            LCD_vidWriteString("Err", strlen("Err") + 1 );
            systick_vidDelay(2000);
            goto Repeat ;
        }

}
void Program_D()
{
     uint8_t i  ;
     char time[4];
     LCD_vidWriteString("Cooking time?", strlen(str) +1);
     //time entry code is still incomplete
     for(i = 0 ; i < 4 ; i++)
     {
         KEYPAD_u8GetButton()
     }
     if(GPIO_u8GetPinValue(GPIO_PORTF,4) == Low) //switch pressed
        LCD_vidClearScreen();
     while(Oven_Ready() == 0) ;
     Turn_on_LEDs() ;
     systic_vidDelay(/*calculated time*/ );
      Turn_off_LEDs() ;
      LCD_vidClearScreen();
}

void Program_Finish()
{
    uint8_t i;

    for(i = 0 ; i < 3 ; i++ )
        {
            GPIO_PORTF_DATA_R ^= 0xE ; //make the LEDS blink
            SoundBuzzer(2500);
            systic_vidDelay(1000); //wait for 1 second between blinking periods
         }

}
uint8_t Oven_Ready()
{
    return ( GPIO_u8GetPinValue(GPIO_PORTE, 0) &&  GPIO_u8GetPinValue(GPIO_PORTF, 0) ; //external switch connected t port E pin 0 and SW2
}

void Turn_on_LEDs()
{
   uint8_t i;
   for(i = 1 ; i<= 3 ; i++ )
     GPIO_vidSetPinValue(GPIO_PORTF ,i , High) ;
}

void Turn_off_LEDs()
{
   uint8_t i;
   for(i = 1 ; i<= 3 ; i++ )
     GPIO_vidSetPinValue(GPIO_PORTF ,i , Low) ;
}
void SoundBuzzer(double frequency)
{

}
