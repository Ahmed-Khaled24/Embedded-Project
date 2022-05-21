#ifndef PROGRAMS_H_INCLUDED
#define PROGRAMS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "../GPIO/GPIO_driver.h"
#include "../LCD/LCD.h"
#include "../Systick/Systick.h"
#include "string.h"
#include "../Keypad/Keypad_interface.h"
#include "../Keypad/Keypad_configration.h"
#define BEEF_DEFROST_RATE 30
#define CHICKEN_DEFROST_RATE 12

void Buzzer_Init(void); // to intialize the buzzer
void External_Button_Init(void); // to intialize the push button
void SW1_Interrupt(void); //for SW1 interrupt conditions
void SW3_Interrupt(void); //for SW2 interrupt condition
void Program_A(void) ; //for popcorn
void Program_B_or_C(uint8_t key); //for beef and chicken
void Program_D(void); //for others
void Program_Finish(void); //the finishing program is for LEDs and buzzer in the end
uint8_t Oven_Ready(void); //to check if the door is closed and SW2 is pressed
void Turn_on_LEDs(void); //to turn on the three LEDs in the microcontroller
void Turn_off_LEDs(void); //to turn off the three LEDs in the microcontroller
void tuneBuzzer(void); //a function to use the buzzer
#endif // PROGRAMS_H_INCLUDED
