
#ifndef INTERRUPT_DRIVER_H
#define INTERRUPT_DRIVER_H

#include "TM4C123.h"                    // Device header
#include "GPIO_driver.h"
#include <stdint.h>

void Interrupt_init(uint8_t pn);// pin number 1 or 4
void GPIOF_Handler(void (*f)(void));
#endif
