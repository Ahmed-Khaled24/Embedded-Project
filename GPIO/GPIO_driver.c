/*********************************************************************

//created by Ghaith Bassam Zaza 21/4/22
last edited 23/4/22

*********************************************************************/

#include "GPIO_driver.h"


void GPIO_vidSetPinValue(uint8_t u8PortNumberCpy, uint8_t u8PinNumberCpy, uint8_t u8ValueCpy){
	switch (u8PortNumberCpy)
  {
  case 0:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTA_DATA_R , u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTA_DATA_R, u8PinNumberCpy);
    }
    break;

  case 1:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTB_DATA_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTB_DATA_R, u8PinNumberCpy);
    }
    break;

  case 2:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTC_DATA_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTC_DATA_R, u8PinNumberCpy);
    }
    break;

  case 3:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTD_DATA_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTD_DATA_R, u8PinNumberCpy);
    }
    break;
	case 4:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTE_DATA_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTE_DATA_R, u8PinNumberCpy);
    }
    break;
	case 5:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTF_DATA_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTF_DATA_R, u8PinNumberCpy);
    }
    break;

  default:
    break;
  }
}

uint8_t GPIO_u8GetPinValue(uint8_t u8PortNumberCpy, uint8_t u8PinNumberCpy){
	uint8_t Loc_u8PinValue = 0;
  switch (u8PortNumberCpy)
  {
  case 0:

    Loc_u8PinValue = GET_BIT(GPIO_PORTA_DATA_R, u8PinNumberCpy);
    break;

  case 1:

    Loc_u8PinValue = GET_BIT(GPIO_PORTB_DATA_R, u8PinNumberCpy);
    break;

  case 2:

    Loc_u8PinValue = GET_BIT(GPIO_PORTC_DATA_R, u8PinNumberCpy);
    break;

  case 3:

    Loc_u8PinValue = GET_BIT(GPIO_PORTD_DATA_R, u8PinNumberCpy);
    break;
	
	case 4:

    Loc_u8PinValue = GET_BIT(GPIO_PORTE_DATA_R, u8PinNumberCpy);
    break;
	
	case 5:

    Loc_u8PinValue = GET_BIT(GPIO_PORTF_DATA_R, u8PinNumberCpy);
    break;

  default:
    break;

  }
  return Loc_u8PinValue;
}


void GPIO_vidSetPinDirection(uint8_t u8PortNumberCpy, uint8_t u8PinNumberCpy, uint8_t u8DirectionCpy){
	switch (u8PortNumberCpy)
  {
  case 0:
    if (u8DirectionCpy == 1)
    {
      SET_BIT(GPIO_PORTA_DIR_R , u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTA_DIR_R, u8PinNumberCpy);
    }
    break;

  case 1:
    if (u8DirectionCpy == 1)
    {
      SET_BIT(GPIO_PORTB_DIR_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTB_DIR_R, u8PinNumberCpy);
    }
    break;

  case 2:
    if (u8DirectionCpy == 1)
    {
      SET_BIT(GPIO_PORTC_DIR_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTC_DIR_R, u8PinNumberCpy);
    }
    break;

  case 3:
    if (u8DirectionCpy == 1)
    {
      SET_BIT(GPIO_PORTD_DIR_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTD_DIR_R, u8PinNumberCpy);
    }
    break;
	case 4:
    if (u8DirectionCpy == 1)
    {
      SET_BIT(GPIO_PORTE_DIR_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTE_DIR_R, u8PinNumberCpy);
    }
    break;
	case 5:
    if (u8DirectionCpy == 1)
    {
      SET_BIT(GPIO_PORTF_DIR_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTF_DIR_R, u8PinNumberCpy);
    }
    break;

  default:
    break;
  }
}


void GPIO_vidSetPortDirection(uint8_t u8PortNumberCpy, uint8_t u8ValueCpy){
	switch (u8PortNumberCpy)
  {
  case 0:
    GPIO_PORTA_DIR_R = u8ValueCpy;
    break;

  case 1:
    GPIO_PORTB_DIR_R = u8ValueCpy;
    break;

  case 2:
    GPIO_PORTC_DIR_R = u8ValueCpy;
    break;

  case 3:
    GPIO_PORTD_DIR_R = u8ValueCpy;
    break;
	
	case 4:
    GPIO_PORTE_DIR_R = u8ValueCpy;
    break;
	
	case 5:
    GPIO_PORTF_DIR_R = u8ValueCpy;
    break;

  default:
    break;
  }
}


void GPIO_vidSetPortValue(uint8_t u8PortNumberCpy, uint8_t u8ValueCpy){
	switch (u8PortNumberCpy)
  {
  case 0:
    GPIO_PORTA_DATA_R = u8ValueCpy;
    break;

  case 1:
    GPIO_PORTB_DATA_R = u8ValueCpy;
    break;

  case 2:
    GPIO_PORTC_DATA_R = u8ValueCpy;
    break;

  case 3:
    GPIO_PORTD_DATA_R = u8ValueCpy;
    break;
	
	case 4:
    GPIO_PORTE_DATA_R = u8ValueCpy;
    break;
	
	case 5:
    GPIO_PORTF_DATA_R = u8ValueCpy;
    break;

  default:
    break;
  }
}

uint8_t GPIO_u8GetPortValue(uint8_t u8PortNumberCpy){
  uint8_t LOC_u8Return = 0x00;
	switch (u8PortNumberCpy)
  {
		case 0:
			LOC_u8Return = GPIO_PORTA_DATA_R;
			break;

		case 1:
			LOC_u8Return = GPIO_PORTB_DATA_R;
			break;

		case 2:
			LOC_u8Return = GPIO_PORTC_DATA_R;
			break;

		case 3:
			LOC_u8Return = GPIO_PORTD_DATA_R;
			break;
		
		case 4:
			LOC_u8Return = GPIO_PORTE_DATA_R;
			break;
		
		case 5:
			LOC_u8Return = GPIO_PORTF_DATA_R;
			break;

		default:
			break;

  }
  return (LOC_u8Return);
}

void GPIO_vidActPinAlternateFunction(uint8_t u8PortNumberCpy, uint8_t u8PinNumberCpy, uint8_t u8ValueCpy){
	switch (u8PortNumberCpy)
  {
  case 0:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTA_AFSEL_R , u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTA_AFSEL_R, u8PinNumberCpy);
    }
    break;

  case 1:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTB_AFSEL_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTB_AFSEL_R, u8PinNumberCpy);
    }
    break;

  case 2:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTC_AFSEL_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTC_AFSEL_R, u8PinNumberCpy);
    }
    break;

  case 3:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTD_AFSEL_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTD_AFSEL_R, u8PinNumberCpy);
    }
    break;
	case 4:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTE_AFSEL_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTE_AFSEL_R, u8PinNumberCpy);
    }
    break;
	case 5:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTF_AFSEL_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTF_AFSEL_R, u8PinNumberCpy);
    }
    break;

  default:
    break;
  }
}

void GPIO_vidActPortAlternateFunction(uint8_t u8PortNumberCpy, uint8_t u8ValueCpy){
	switch (u8PortNumberCpy)
  {
  case 0:
    GPIO_PORTA_AFSEL_R = u8ValueCpy;
    break;

  case 1:
    GPIO_PORTB_AFSEL_R = u8ValueCpy;
    break;

  case 2:
    GPIO_PORTC_AFSEL_R = u8ValueCpy;
    break;

  case 3:
    GPIO_PORTD_AFSEL_R = u8ValueCpy;
    break;
	
	case 4:
    GPIO_PORTE_AFSEL_R = u8ValueCpy;
    break;
	
	case 5:
    GPIO_PORTF_AFSEL_R = u8ValueCpy;
    break;

  default:
    break;
  }
}

void GPIO_vidSetPinDigitalEnable(uint8_t u8PortNumberCpy, uint8_t u8PinNumberCpy, uint8_t u8ValueCpy){
	switch (u8PortNumberCpy)
  {
  case 0:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTA_DEN_R , u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTA_DEN_R, u8PinNumberCpy);
    }
    break;

  case 1:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTB_DEN_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTB_DEN_R, u8PinNumberCpy);
    }
    break;

  case 2:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTC_DEN_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTC_DEN_R, u8PinNumberCpy);
    }
    break;

  case 3:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTD_DEN_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTD_DEN_R, u8PinNumberCpy);
    }
    break;
	case 4:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTE_DEN_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTE_DEN_R, u8PinNumberCpy);
    }
    break;
	case 5:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTF_DEN_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTF_DEN_R, u8PinNumberCpy);
    }
    break;

  default:
    break;
  }
}

void GPIO_vidSetPortDigitalEnable(uint8_t u8PortNumberCpy, uint8_t u8ValueCpy){
	switch (u8PortNumberCpy)
  {
  case 0:
    GPIO_PORTA_DEN_R = u8ValueCpy;
    break;

  case 1:
    GPIO_PORTB_DEN_R = u8ValueCpy;
    break;

  case 2:
    GPIO_PORTC_DEN_R = u8ValueCpy;
    break;

  case 3:
    GPIO_PORTD_DEN_R = u8ValueCpy;
    break;
	
	case 4:
    GPIO_PORTE_DEN_R = u8ValueCpy;
    break;
	
	case 5:
    GPIO_PORTF_DEN_R = u8ValueCpy;
    break;

  default:
    break;
  }
}

void GPIO_vidSetPinAnalogEnable(uint8_t u8PortNumberCpy, uint8_t u8PinNumberCpy, uint8_t u8ValueCpy){
	switch (u8PortNumberCpy)
  {
  case 0:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTA_AMSEL_R , u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTA_AMSEL_R, u8PinNumberCpy);
    }
    break;

  case 1:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTB_AMSEL_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTB_AMSEL_R, u8PinNumberCpy);
    }
    break;

  case 2:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTC_AMSEL_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTC_AMSEL_R, u8PinNumberCpy);
    }
    break;

  case 3:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTD_AMSEL_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTD_AMSEL_R, u8PinNumberCpy);
    }
    break;
	case 4:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTE_AMSEL_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTE_AMSEL_R, u8PinNumberCpy);
    }
    break;
	case 5:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTF_AMSEL_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTF_AMSEL_R, u8PinNumberCpy);
    }
    break;

  default:
    break;
  }
}

void GPIO_vidSetPortAnalogEnable(uint8_t u8PortNumberCpy, uint8_t u8ValueCpy){
	switch (u8PortNumberCpy)
  {
  case 0:
    GPIO_PORTA_AMSEL_R = u8ValueCpy;
    break;

  case 1:
    GPIO_PORTB_AMSEL_R = u8ValueCpy;
    break;

  case 2:
    GPIO_PORTC_AMSEL_R = u8ValueCpy;
    break;

  case 3:
    GPIO_PORTD_AMSEL_R = u8ValueCpy;
    break;
	
	case 4:
    GPIO_PORTE_AMSEL_R = u8ValueCpy;
    break;
	
	case 5:
    GPIO_PORTF_AMSEL_R = u8ValueCpy;
    break;

  default:
    break;
  }
}

void GPIO_vidSetPinPullUpRes(uint8_t u8PortNumberCpy, uint8_t u8PinNumberCpy, uint8_t u8ValueCpy){
	switch (u8PortNumberCpy)
  {
  case 0:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTA_PUR_R , u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTA_PUR_R, u8PinNumberCpy);
    }
    break;

  case 1:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTB_PUR_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTB_PUR_R, u8PinNumberCpy);
    }
    break;

  case 2:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTC_PUR_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTC_PUR_R, u8PinNumberCpy);
    }
    break;

  case 3:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTD_PUR_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTD_PUR_R, u8PinNumberCpy);
    }
    break;
	case 4:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTE_PUR_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTE_PUR_R, u8PinNumberCpy);
    }
    break;
	case 5:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTF_PUR_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTF_PUR_R, u8PinNumberCpy);
    }
    break;

  default:
    break;
  }
}

void GPIO_vidSetPortPullUpRes(uint8_t u8PortNumberCpy, uint8_t u8ValueCpy){
	switch (u8PortNumberCpy)
  {
  case 0:
    GPIO_PORTA_PUR_R = u8ValueCpy;
    break;

  case 1:
    GPIO_PORTB_PUR_R = u8ValueCpy;
    break;

  case 2:
    GPIO_PORTC_PUR_R = u8ValueCpy;
    break;

  case 3:
    GPIO_PORTD_PUR_R = u8ValueCpy;
    break;
	
	case 4:
    GPIO_PORTE_PUR_R = u8ValueCpy;
    break;
	
	case 5:
    GPIO_PORTF_PUR_R = u8ValueCpy;
    break;

  default:
    break;
  }
}


void GPIO_vidSetPinPullDownRes(uint8_t u8PortNumberCpy, uint8_t u8PinNumberCpy, uint8_t u8ValueCpy){
	switch (u8PortNumberCpy)
  {
  case 0:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTA_PDR_R , u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTA_PDR_R, u8PinNumberCpy);
    }
    break;

  case 1:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTB_PDR_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTB_PDR_R, u8PinNumberCpy);
    }
    break;

  case 2:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTC_PDR_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTC_PDR_R, u8PinNumberCpy);
    }
    break;

  case 3:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTD_PDR_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTD_PDR_R, u8PinNumberCpy);
    }
    break;
	case 4:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTE_PDR_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTE_PDR_R, u8PinNumberCpy);
    }
    break;
	case 5:
    if (u8ValueCpy == 1)
    {
      SET_BIT(GPIO_PORTF_PDR_R, u8PinNumberCpy);
    }
    else
    {
      CLEAR_BIT(GPIO_PORTF_PDR_R, u8PinNumberCpy);
    }
    break;

  default:
    break;
  }
}

void GPIO_vidSetPortPullDownRes(uint8_t u8PortNumberCpy, uint8_t u8ValueCpy){
	switch (u8PortNumberCpy)
  {
  case 0:
    GPIO_PORTA_PDR_R = u8ValueCpy;
    break;

  case 1:
    GPIO_PORTB_PDR_R = u8ValueCpy;
    break;

  case 2:
    GPIO_PORTC_PDR_R = u8ValueCpy;
    break;

  case 3:
    GPIO_PORTD_PDR_R = u8ValueCpy;
    break;
	
	case 4:
    GPIO_PORTE_PDR_R = u8ValueCpy;
    break;
	
	case 5:
    GPIO_PORTF_PDR_R = u8ValueCpy;
    break;

  default:
    break;
  }
}
void GPIO_vidClkActivate(uint8_t u8PortNumberCpy,uint8_t u8ValueCpy){
	if(u8ValueCpy == 1){
		SET_BIT(SYSCTL_RCGCGPIO_R, u8PortNumberCpy);
	}else{
		CLEAR_BIT(SYSCTL_RCGCGPIO_R, u8PortNumberCpy);
	}
	
	while(GET_BIT(SYSCTL_PRGPIO_R,u8PortNumberCpy) != GET_BIT(SYSCTL_RCGCGPIO_R,u8PortNumberCpy)){}
}

void GPIO_vidSetPortAlternateFunc(uint8_t u8PortNumberCpy,uint8_t u8PCTLValCpy){
	switch (u8PortNumberCpy)
  {
  case 0:
    CPY_HB_repeated4B(GPIO_PORTA_PCTL_R,u8PCTLValCpy);
    break;

  case 1:
    CPY_HB_repeated4B(GPIO_PORTB_PCTL_R,u8PCTLValCpy);
    break;

  case 2:
    CPY_HB_repeated4B(GPIO_PORTC_PCTL_R,u8PCTLValCpy);
    break;

  case 3:
    CPY_HB_repeated4B(GPIO_PORTD_PCTL_R,u8PCTLValCpy);
    break;
	
	case 4:
    CPY_HB_repeated5HB(GPIO_PORTE_PCTL_R,u8PCTLValCpy);
    break;
	
	case 5:
    CPY_HB_repeated3B(GPIO_PORTF_PCTL_R,u8PCTLValCpy);
    break;

  default:
    break;
  }
}

void GPIO_vidSetPinAlternateFunc(uint8_t u8PortNumberCpy,uint8_t u8PinNumberCpy,uint32_t u8PCTLValCpy){
	switch (u8PortNumberCpy)
  {
  case 0:
    CPY_HB(GPIO_PORTA_PCTL_R,u8PinNumberCpy,u8PCTLValCpy);
    break;

  case 1:
    CPY_HB(GPIO_PORTB_PCTL_R,u8PinNumberCpy,u8PCTLValCpy);
    break;

  case 2:
    CPY_HB(GPIO_PORTC_PCTL_R,u8PinNumberCpy,u8PCTLValCpy);
    break;

  case 3:
    CPY_HB(GPIO_PORTD_PCTL_R,u8PinNumberCpy,u8PCTLValCpy);
    break;
	
	case 4:
    CPY_HB(GPIO_PORTE_PCTL_R,u8PinNumberCpy,u8PCTLValCpy);
    break;
	
	case 5:
    CPY_HB(GPIO_PORTF_PCTL_R,u8PinNumberCpy,u8PCTLValCpy);
    break;

  default:
    break;
  }
}

void GPIO_vidUnlockPF0(void){
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R |= 0x1F;
}

void GPIO_vidUnlockPD7(void){
	GPIO_PORTD_LOCK_R = 0x4C4F434B;
	GPIO_PORTD_CR_R = 0xFF;
}

void GPIO_DIO_vidPortInit(uint8_t u8PortNumberCpy){
	GPIO_vidClkActivate(u8PortNumberCpy,High);
	if(u8PortNumberCpy==GPIO_PORTD)GPIO_vidUnlockPD7();
	else if(u8PortNumberCpy==GPIO_PORTF)GPIO_vidUnlockPF0();
	GPIO_vidSetPortAnalogEnable(u8PortNumberCpy,Low);
	GPIO_vidActPortAlternateFunction(u8PortNumberCpy,Low);
	if(u8PortNumberCpy == GPIO_PORTF)GPIO_vidSetPortDigitalEnable(u8PortNumberCpy,0x1F);
	else if(u8PortNumberCpy == GPIO_PORTE)GPIO_vidSetPortDigitalEnable(u8PortNumberCpy,0x3F);
	else GPIO_vidSetPortDigitalEnable(u8PortNumberCpy,0xFF);
	GPIO_vidSetPortAlternateFunc(u8PortNumberCpy,0);
	
}

void GPIO_DIO_vidPinInit(uint8_t u8PortNumberCpy,uint8_t u8PinNumberCpy){
	GPIO_vidClkActivate(u8PortNumberCpy,High);
	if(u8PortNumberCpy==GPIO_PORTD && u8PinNumberCpy==7)GPIO_vidUnlockPD7();
	else if(u8PortNumberCpy==GPIO_PORTF && u8PinNumberCpy==0)GPIO_vidUnlockPF0();
	GPIO_vidSetPinAnalogEnable(u8PortNumberCpy,u8PinNumberCpy,Low);
	GPIO_vidActPinAlternateFunction(u8PortNumberCpy,u8PinNumberCpy,Low);
	GPIO_vidSetPinDigitalEnable(u8PortNumberCpy,u8PinNumberCpy,High);
	GPIO_vidSetPinAlternateFunc(u8PortNumberCpy,u8PinNumberCpy,0);
}
