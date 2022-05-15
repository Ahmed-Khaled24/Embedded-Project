/*
    author : Mina Mounir Farid
*/

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
#define BEEF_DEFROST_RATE 0.5
#define CHICKEN_DEFROST_RATE 0.2

void Program_Interrupt(); //for interrupt conditions
void Program_A() ; //for popcorn
void Program_B_or_C(uint8_t key); //for beef and chicken
void Program_D(); //for others
void Program_Finish(); //the finishing program is for LEDs and buzzer in the end
uint8_t Oven_Ready(); //to check if the door is closed and SW2 is pressed
void Turn_on_LEDs(); //to turn on the three LEDs in the microcontroller
void Turn_off_LEDs(); //to turn off the three LEDs in the microcontroller
void tuneBuzzer(void); //a function to use the buzzer 
#endif // PROGRAMS_H_INCLUDED
