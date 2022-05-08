#include "stdint.h"
#ifndef SYSTIC_DRIVER_H
#define SYSTIC_DRIVER_H


void systic_vidInit(void);
void systic_vid1msDelay();
void systic_vid1MicroDelay();
void systic_vidDelay(unsigned uint32_t ms);
#endif
