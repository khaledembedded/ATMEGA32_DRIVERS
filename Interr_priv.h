/*
 * Interr_priv.h
 *
 *  Created on: Mar 19, 2020
 *      Author: khaled
 */

#ifndef INTERR_PRIV_H_
#define INTERR_PRIV_H_

#define SREG (*(volatile Reg_type *)0x5F)
#define GICR (*(volatile Reg_type *)0x5B)
#define MCUCR (*(volatile Reg_type *)0x55)

typedef union Reg_type Reg_type ;
union Reg_type
{
	struct
	{
		u8 bit0:1;
		u8 bit1:1;
		u8 bit2:1;
		u8 bit3:1;
		u8 bit4:1;
		u8 bit5:1;
		u8 bit6:1;
		u8 bit7:1;
	}Bits;

	u8 Byte;
};

#endif /* INTERR_PRIV_H_ */
