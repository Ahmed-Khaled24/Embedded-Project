#include "stdint.h"
#ifndef SYSTIC_DRIVER_H
#define SYSTIC_DRIVER_H


void systick_vidInit(void);
void systick_vid1msDelay();
void systick_Disable();
void systick_Enable();
void systick_vid1MicroDelay();
void systick_vidDelay(uint32_t ms);

#endif
