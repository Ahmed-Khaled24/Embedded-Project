

#ifndef MACROS_H
#define MACROS_H

#define SET_BIT(Byte,Pos)                       (Byte |= (1<<Pos))
#define CLEAR_BIT(Byte,Pos)                     (Byte &= ~(1<<Pos))
#define TOGGLE_BIT(Byte,Pos)                    (Byte ^=(1<<Pos))
#define SET_BYTE(Byte)                          (Byte |=(0xFF))
#define CLEAR_BYTE(Byte)                        (Byte &=(0x00))
#define SET_NIBBLE_HIGH(Byte)                   (Byte |=(0xF0))
#define SET_NIBBLE_LOW(Byte)                    (Byte |=(0x0F))
#define CLEAR_NIBBLE_HIGH(Byte)                 (Byte &=(0x0F))
#define CLEAR_NIBBLE_LOW(Byte)                  (Byte &=(0xF0))
#define GET_BIT(Reg,Bit)                        ((Reg &(1<<Bit))>>Bit)

#define CPY_HB(Reg,HB_N,HB)											Reg = (Reg & ~(0x000F<<(HB_N *4))) | (HB<<(HB_N *4)) 

#define CPY_HB_repeated1B(Reg,HB)								Reg = (HB | (HB<<4))

#define CPY_HB_repeated2B(Reg,HB)								CPY_HB_repeated1B(Reg,HB);\
																								Reg = (Reg | (Reg<<8))
																								
#define CPY_HB_repeated5HB(Reg,HB)							CPY_HB_repeated2B(Reg,HB);\
																								Reg = (Reg | (HB<<16))
																								
#define CPY_HB_repeated3B(Reg,HB)								CPY_HB_repeated1B(Reg,HB);\
																								Reg = (Reg | (Reg<<8) | (Reg<<16))
																								
#define CPY_HB_repeated4B(Reg,HB)								CPY_HB_repeated2B(Reg,HB);\
																								Reg = (Reg | (Reg<<16))


#endif
