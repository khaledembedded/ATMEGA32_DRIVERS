/*
 * Dio_Priv.h
 *
 *  Created on: Mar 9, 2020
 *      Author: khaled
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#define PORTA (*(volatile Reg_type *)0x3B)
#define DDRA (*(volatile Reg_type *)0x3A)
#define PINA (*(volatile Reg_type *)0x39)

#define PORTB (*(volatile Reg_type *)0x38)
#define DDRB (*(volatile Reg_type *)0x37)
#define PINB (*(volatile Reg_type *)0x36)

#define PORTC (*(volatile Reg_type *)0x35)
#define DDRC (*(volatile Reg_type *)0x34)
#define PINC (*(volatile Reg_type *)0x33)

#define PORTD (*(volatile Reg_type *)0x32)
#define DDRD (*(volatile Reg_type *)0x31)
#define PIND (*(volatile Reg_type *)0x30)

typedef union Reg_type Reg_type ;

union Reg_type
{
	struct
	{
		u8 pin0:1;
		u8 pin1:1;
		u8 pin2:1;
		u8 pin3:1;
		u8 pin4:1;
		u8 pin5:1;
		u8 pin6:1;
		u8 pin7:1;
	}Bits;

	u8 Byte;
};


#endif /* DIO_PRIV_H_ */
