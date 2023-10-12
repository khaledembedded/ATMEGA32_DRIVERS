/*
 * Timer0_priv.h
 *
 *  Created on: Mar 25, 2020
 *      Author: Admin
 */

#ifndef TIMER0_PRIV_H_
#define TIMER0_PRIV_H_


void __vector__11(void) __attribute__((signal,used,externally_visible));

typedef union {
	struct{
		u8 CS00:1;
		u8 CS01:1;
		u8 CS02:1;
		u8 WGM01:1;
		u8 COM00:1;
		u8 COM01:1;
		u8 WGM00:1;
		u8 FOC0:1;
	}Bits;
	u8 Byte;
}Timer0_TCCR0_type;

typedef union {
	struct{
		u8 B0:1;
		u8 B1:1;
		u8 B2:1;
		u8 B3:1;
		u8 B4:1;
		u8 B5:1;
		u8 B6:1;
		u8 B7:1;
	}Bits;
	u8 Byte;
}Timer0_TCNT0_type;

typedef union {
	struct{
		u8 B0:1;
		u8 B1:1;
		u8 B2:1;
		u8 B3:1;
		u8 B4:1;
		u8 B5:1;
		u8 B6:1;
		u8 B7:1;
	}Bits;
	u8 Byte;
}Timer0_OCR0_type;

typedef union {
	struct{
		u8 TOIE0:1;
		u8 OCIE0:1;
		u8 TOIE1:1;
		u8 OCIE1B:1;
		u8 OCIE1A:1;
		u8 TICIE1:1;
		u8 TOIE2:1;
		u8 OCIE2:1;
	}Bits;
	u8 Byte;
}Timer0_TIMSK_type;

typedef union {
	struct{
		u8 TOV0:1;
		u8 OCF0:1;
		u8 TOV1:1;
		u8 OCF1B:1;
		u8 OCF1A:1;
		u8 ICF1:1;
		u8 TOV2:1;
		u8 OCF2:1;
	}Bits;
	u8 Byte;
}Timer0_TIFR_type;

typedef union {
	struct{
		u8 C:1;
		u8 Z:1;
		u8 N:1;
		u8 V:1;
		u8 S:1;
		u8 H:1;
		u8 T:1;
		u8 I:1;
	}Bits;
	u8 Byte;
}SREG_type;


#define TCCR0    (*(volatile Timer0_TCCR0_type*)0x53)
#define OCR0     (*(volatile Timer0_OCR0_type*)0x5C)
#define TIMSK    (*(volatile Timer0_TIMSK_type*)0x59)
#define TIFR     (*(volatile Timer0_TIFR_type*)0x85)
#define SREG     (*(volatile SREG_type *)0x5F)
#define TCNT0     (*(volatile Timer0_TCNT0_type *)0x52)



#endif /* TIMER0_PRIV_H_ */
