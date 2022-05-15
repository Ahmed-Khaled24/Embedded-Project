
#ifndef INTERRUPT_DRIVER_H
#define INTERRUPT_DRIVER_H

               
#include "GPIO_driver.h"
#include <stdint.h>
#include <GPIO\TM4C123GH6PM.h>
#include "TM4C123.h"

void Interrupt_init(uint8_t pn);// pin number 1 or 4
void GPIOF_setHandler(void (*f)(void));

#endif
