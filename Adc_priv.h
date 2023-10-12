/*
 * Adc_priv.h
 *
 *  Created on: Mar 10, 2020
 *      Author: khaled
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_
#define ADMUX (*(volatile Reg_type *)0x27)
#define ADCSRA (*(volatile Reg_type *)0x26)
#define ADCH (*(volatile Reg_type *)0x25)
#define ADCL (*(volatile Reg_type *)0x24)

typedef union Reg_type Reg_type;
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

#endif /* ADC_PRIV_H_ */
