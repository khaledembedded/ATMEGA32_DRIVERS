/*
 * Interr_prg.c
 *
 *  Created on: Mar 19, 2020
 *      Author: khaled
 */
#include "../Lib/Std_types.h"
#include "Dio_int.h"
#include "Interr_priv.h"
#include "Interr_cfg.h"
#include "Interr_int.h"

void(*pfun_0)(void);   //pointer to function
void(*pfun_1)(void);

void INT_vidInit(u8 INT_id)
{
	//global Interrupt Enable
	SREG.Bits.bit7 = 1;

	switch(INT_id)
	{
		case 0:  	//INT0
			//PIE for INT0
			GICR.Bits.bit6 = 1;

			//select interrupt sense control
			#if INT0_PIF_EVENT == INT_PIF_LOW_LEVEL
				MCUCR.Bits.bit1 = 0;
				MCUCR.Bits.bit0 = 0;

			#elif INT0_PIF_EVENT == INT_PIF_ON_CHANGE
				MCUCR.Bits.bit1 = 1;
				MCUCR.Bits.bit0 = 0;

			#elif INT0_PIF_EVENT == INT_PIF_FALLING_EDGE
				MCUCR.Bits.bit1 = 0;
				MCUCR.Bits.bit0 = 1;

			#elif INT0_PIF_EVENT == INT_PIF_RISING_EDGE
				MCUCR.Bits.bit1 = 1;
				MCUCR.Bits.bit0 = 1;

			#endif

				//initialize PIN of INT0
				Dio_vidSetPinDir(DIO_u8PIN_26 , DIO_u8INPUT);
				Dio_vidSetPinVal(DIO_u8PIN_26 , DIO_u8HIGH);
			break;

		case 1:     //INT1
			//PIE for INT1
			GICR.Bits.bit7 = 1;

			//select interrupt sense control
			#if INT1_PIF_EVENT == INT_PIF_LOW_LEVEL
				MCUCR.Bits.bit1 = 0;
				MCUCR.Bits.bit0 = 0;

			#elif INT0_PIF_EVENT == INT_PIF_ON_CHANGE
				MCUCR.Bits.bit1 = 1;
				MCUCR.Bits.bit0 = 0;

			#elif INT0_PIF_EVENT == INT_PIF_FALLING_EDGE
				MCUCR.Bits.bit1 = 0;
				MCUCR.Bits.bit0 = 1;

			#elif INT0_PIF_EVENT == INT_PIF_RISING_EDGE
				MCUCR.Bits.bit1 = 1;
				MCUCR.Bits.bit0 = 1;

			#endif

				//initialize PIN of INT1
				Dio_vidSetPinDir(DIO_u8PIN_27 , DIO_u8INPUT);
				Dio_vidSetPinVal(DIO_u8PIN_27 , DIO_u8HIGH);
			break;

	}
}

//Call_Back function has an address of another function in main.c for INT0
void INT0_vidSetCB(void(*pf)(void))
{
	pfun_0 = pf;
}
//function has an address of another function in main.c for INT1
void INT1_vidSetCB(void(*pf)(void))
{
	pfun_1 = pf;
}
//ISR OF INT0
void __vector_1 (void)
{
	pfun_0();
}
//ISR OF INT1
void __vector_2 (void)
{
	pfun_1();
}
