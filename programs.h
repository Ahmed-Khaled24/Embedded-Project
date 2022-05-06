/*
    author : Mina Mounir Farid
*/

#ifndef PROGRAMS_H_INCLUDED
#define PROGRAMS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "GPIO_driver.h"
#include "LCD.h"
#include "Systick.h"
#include "string.h"
#define BEEF_DEFROST_RATE 0.5
#define CHICKEN_DEFROST_RATE 0.2
void Program_A(char* str) ; //for popcorn
void Program_B_or_C(char* str , uint8_t key); //for beef and chicken
void Program_D(); //for others
void Program_Finish(); //for LEDs and buzzer in the end
uint8_t Check_Door(); //to check if door is closed
void (*current_program)()  ;
uint8_t Oven_Ready();
void Turn_on_LEDs();
void Turn_off_LEDs();
void tuneBuzzer(uint8_t u8PortNumberCpy , uint8_t u8PinNumberCpy,uint32_t u32FreqCpy_Hz, uint32_t u32TimeCpy_ms);
#endif // PROGRAMS_H_INCLUDED
