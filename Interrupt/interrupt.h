
#ifndef INTERRUPT_DRIVER_H
#define INTERRUPT_DRIVER_H

               
#include "../GPIO/GPIO_driver.h"
#include <stdint.h>
#include "../GPIO/tm4c123gh6pm.h"
#include "TM4C123.h"

void Interrupt_init(uint8_t pn);// pin number 0 or 4
void GPIOF_setHandler(void (*f)(void));

#endif
